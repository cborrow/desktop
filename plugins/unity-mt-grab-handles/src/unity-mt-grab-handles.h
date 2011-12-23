/*
 * Copyright (C) 2011 Canonical Ltd
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authored by: Sam Spilsbury <sam.spilsbury@canonical.com>
 */

#include <Nux/Nux.h>
#include <glib.h>
#include <core/core.h>
#include <composite/composite.h>
#include <opengl/opengl.h>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/weak_ptr.hpp>

#include <core/atoms.h>

#include "unitymtgrabhandles_options.h"

namespace unity
{
namespace MT
{
typedef std::pair <GLTexture::List*, nux::Geometry> TextureSize;
typedef std::pair <GLTexture::List*, nux::Geometry> TextureLayout;

class DummyDamager
{
public:

    void damage (const nux::Geometry &g)
    {
      std::cout << "Damage rects: " << std::endl;
      std::cout << "x: " << g.x << " y: " << g.y << " width: " << g.width << " height: " << g.height << std::endl;
    }
};

/* Update the server side position */
static const unsigned int PositionLock = (1 << 0);

/* Update the client side position */
static const unsigned int PositionSet = (1 << 2);

static const unsigned int TopLeftHandle = (1 << 0);
static const unsigned int TopHandle = (1 << 1);
static const unsigned int TopRightHandle = (1 << 2);
static const unsigned int RightHandle = (1 << 3);
static const unsigned int BottomRightHandle = (1 << 4);
static const unsigned int BottomHandle = (1 << 5);
static const unsigned int BottomLeftHandle = (1 << 6);
static const unsigned int LeftHandle = (1 << 7);
static const unsigned int MiddleHandle = (1 << 8);

static const std::map <unsigned int, int> maskHandles = {
 { TopLeftHandle, 0 },
 { TopHandle, 1 },
 { TopRightHandle, 2 },
 { RightHandle, 3 },
 { BottomRightHandle, 4},
 { BottomHandle, 5 },
 { BottomLeftHandle, 6 },
 { LeftHandle, 7 },
 { MiddleHandle, 8 }
};

static const std::map <int, unsigned int> handlesMask = {
 { 0, TopLeftHandle },
 { 1, TopHandle },
 { 2, TopRightHandle },
 { 3, RightHandle },
 { 4, BottomRightHandle},
 { 5, BottomHandle },
 { 6, BottomLeftHandle },
 { 7, LeftHandle },
 { 8, MiddleHandle }
};

unsigned int getLayoutForMask (unsigned int state,
                               unsigned int actions);

class GrabHandleGroup;

class GrabHandle :
  public boost::enable_shared_from_this <GrabHandle>,
  boost::noncopyable
{
public:

  typedef boost::shared_ptr <GrabHandle> Ptr;

  static GrabHandle::Ptr create (GLTexture::List *texture,
                                 unsigned int    width,
                                 unsigned int    height,
                                 const boost::shared_ptr <GrabHandleGroup> &owner,
                                 unsigned int id);
  ~GrabHandle();

  bool operator== (const GrabHandle &other) const
  {
    return mId == other.mId;
  }

  bool operator!= (const GrabHandle &other) const
  {
    return !(*this == other);
  }

  void buttonPress (int x,
                    int y,
                    unsigned int button) const;

  void requestMovement (int x,
                        int y,
                        unsigned int button) const;

  void reposition(int x,
		  int y,
                  unsigned int flags);
  void reposition(int x, int y, unsigned int flags) const;

  void show();
  void hide();
  void raise() const;

  TextureLayout layout();

  unsigned int id () const { return mId; }
  unsigned int width () const { return mRect.width; }
  unsigned int height () const { return mRect.height; }
  int          x () const { return mRect.x; }
  int          y () const { return mRect.y; }

  void damage (const nux::Geometry &g) const { mImpl->damage (g); }

public:

  class Impl :
    boost::noncopyable
  {
    public:

      virtual ~Impl () {};

      virtual void show () = 0;
      virtual void hide () = 0;

      virtual void buttonPress (int x,
                                int y,
                                unsigned int button) const = 0;

      virtual void lockPosition (int x,
                                 int y,
                                 unsigned int flags) = 0;

      virtual void damage (const nux::Geometry &g) = 0;
  };

  class ImplFactory
  {
    public:

      virtual ~ImplFactory() {};

      static ImplFactory *
      Default();

      static void
      SetDefault(ImplFactory *);

      virtual GrabHandle::Impl * create(const GrabHandle::Ptr &h) = 0;

    protected:

      static ImplFactory *mDefault;

      ImplFactory() {};
  };

private:

  GrabHandle(GLTexture::List *texture,
             unsigned int    width,
             unsigned int    height,
             const boost::shared_ptr <GrabHandleGroup> &owner,
             unsigned int id);

  boost::weak_ptr <GrabHandleGroup>      mOwner;
  GLTexture::List                        *mTexture;
  unsigned int                           mId;
  nux::Geometry                          mRect;
  Impl                                   *mImpl;
};

class X11ImplFactory :
  public GrabHandle::ImplFactory
{
  public:

    X11ImplFactory (Display *dpy);

    GrabHandle::Impl * create (const GrabHandle::Ptr &h);
  private:
    Display *mDpy;
};

class X11GrabHandleImpl :
  public GrabHandle::Impl
{
public:

  X11GrabHandleImpl (Display *dpy, const GrabHandle::Ptr &h);
  ~X11GrabHandleImpl ();

public:

  void show ();
  void hide ();

  void buttonPress (int x,
                    int y,
                    unsigned int button) const;

  void lockPosition (int x,
                     int y,
                     unsigned int flags);

  void damage (const nux::Geometry &g)
  {
    CompRegion r (g.x, g.y, g.width, g.height);
    CompositeScreen::get (screen)->damageRegion (r);
  }

private:

  boost::weak_ptr <unity::MT::GrabHandle>  mGrabHandle;
  Window                                   mIpw;
  Display                                  *mDpy;
};

class GrabHandleWindow
{
  public:

    virtual ~GrabHandleWindow () {};
    virtual void requestMovement (int x,
                                  int y,
                                  unsigned int direction,
				  unsigned int button) = 0;
    virtual void raiseGrabHandle (const boost::shared_ptr <const unity::MT::GrabHandle> &) = 0;
};

class GrabHandleGroup :
  public boost::enable_shared_from_this <GrabHandleGroup>,
  boost::noncopyable
{
public:

  typedef boost::shared_ptr <GrabHandleGroup> Ptr;

  static GrabHandleGroup::Ptr create (GrabHandleWindow *owner,
                                      std::vector<TextureSize> &textures);
  ~GrabHandleGroup();

  void relayout(const nux::Geometry&, bool);
  void restack();

  bool visible();
  bool animate(unsigned int);
  bool needsAnimate();

  int opacity();

  void hide();
  void show(unsigned int handles = ~0);
  void raiseHandle (const boost::shared_ptr <const unity::MT::GrabHandle> &);

  std::vector <TextureLayout> layout(unsigned int handles);

  void forEachHandle (const std::function<void (const unity::MT::GrabHandle::Ptr &)> &);

  void requestMovement (int x,
                        int y,
                        unsigned int direction,
                        unsigned int button);
private:

  GrabHandleGroup(GrabHandleWindow *owner,
                  std::vector<TextureSize> &textures);

  enum class State
  {
    FADE_IN = 1,
    FADE_OUT,
    NONE
  };

  State  			      mState;
  int   			      mOpacity;

  bool 				           mMoreAnimate;
  std::vector <unity::MT::GrabHandle::Ptr> mHandles;
  GrabHandleWindow 		           *mOwner;
};
};
};

class UnityMTGrabHandlesScreen :
  public PluginClassHandler <UnityMTGrabHandlesScreen, CompScreen>,
  public ScreenInterface,
  public CompositeScreenInterface,
  public GLScreenInterface,
  public UnitymtgrabhandlesOptions
{
public:

  UnityMTGrabHandlesScreen(CompScreen*);
  ~UnityMTGrabHandlesScreen();

  CompositeScreen* cScreen;
  GLScreen*  gScreen;

public:

  void handleEvent(XEvent*);

  bool toggleHandles(CompAction*         action,
                     CompAction::State  state,
                     CompOption::Vector& options);

  bool showHandles(CompAction*         action,
                   CompAction::State  state,
                   CompOption::Vector& options);

  bool hideHandles(CompAction*         action,
                   CompAction::State  state,
                   CompOption::Vector& options);

  void addHandles(const unity::MT::GrabHandleGroup::Ptr & handles);
  void removeHandles(const unity::MT::GrabHandleGroup::Ptr & handles);

  void addHandleWindow(const unity::MT::GrabHandle::Ptr &, Window);
  void removeHandleWindow(Window);

  void preparePaint(int);
  void donePaint();

  void raiseHandle (const boost::shared_ptr <const unity::MT::GrabHandle> &,
                    Window                      owner);

  std::vector <unity::MT::TextureSize>  & textures()
  {
    return mHandleTextures;
  }

private:

  std::list <unity::MT::GrabHandleGroup::Ptr> mGrabHandles;
  std::vector <unity::MT::TextureSize> mHandleTextures;

  std::map <Window, const unity::MT::GrabHandle::Ptr> mInputHandles;
  CompWindowVector         		    mLastClientListStacking;
  Atom             			    mCompResizeWindowAtom;

  bool          mMoreAnimate;
};

#define UMTGH_SCREEN(screen)                  \
    UnityMTGrabHandlesScreen *us = UnityMTGrabHandlesScreen::get (screen)

class UnityMTGrabHandlesWindow :
  public PluginClassHandler <UnityMTGrabHandlesWindow, CompWindow>,
  public WindowInterface,
  public CompositeWindowInterface,
  public GLWindowInterface,
  public unity::MT::GrabHandleWindow
{
public:

  UnityMTGrabHandlesWindow(CompWindow*);
  ~UnityMTGrabHandlesWindow();

  CompWindow*  window;
  CompositeWindow* cWindow;
  GLWindow*  gWindow;

public:

  bool allowHandles();
  bool handleTimerActive();

  void grabNotify(int, int, unsigned int, unsigned int);
  void ungrabNotify();

  void relayout(const CompRect&, bool);

  void getOutputExtents(CompWindowExtents& output);

  void moveNotify(int dx, int dy, bool immediate);

  bool glDraw(const GLMatrix&,
              GLFragment::Attrib&,
              const CompRegion&,
              unsigned int);

  bool    handlesVisible();
  void    hideHandles();
  void    showHandles(bool use_timer);
  void    restackHandles();

  void resetTimer();
  void disableTimer();

protected:

  void raiseGrabHandle (const boost::shared_ptr <const unity::MT::GrabHandle> &h);
  void requestMovement (int x,
                        int y,
                        unsigned int direction,
			unsigned int button);

private:

  bool onHideTimeout();

  unity::MT::GrabHandleGroup::Ptr mHandles;
  CompTimer                       mTimer;
};

#define UMTGH_WINDOW(window)                  \
    UnityMTGrabHandlesWindow *uw = UnityMTGrabHandlesWindow::get (window)

class UnityMTGrabHandlesPluginVTable :
  public CompPlugin::VTableForScreenAndWindow < UnityMTGrabHandlesScreen,
  UnityMTGrabHandlesWindow >
{
public:

  bool init();
};
