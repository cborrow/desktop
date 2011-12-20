import gio
from subprocess import call
from time import sleep

from testtools import TestCase
from testtools.matchers import Equals
from testtools.matchers import NotEquals

from compizconfig import Setting
from compizconfig import Plugin

from autopilot.globals import global_context
from autopilot.emulators.unity import Switcher
from autopilot.glibrunner import GlibRunner



class SwitcherTests(TestCase):
    run_test_with = GlibRunner

    def launch_application(self, desktop_file):
        proc = gio.unix.DesktopAppInfo(desktop_file)
        proc.launch()

    def set_timeout_setting(self, value):
        self.setting.Value = value
        global_context.Write()
        
    def setUp(self):
        self.plugin = Plugin(global_context, "unityshell")
        self.setting = Setting(self.plugin, "alt_tab_timeout")

        self.launch_application("gucharmap.desktop")
        self.launch_application("gcalctool.desktop")
        self.launch_application("users-admin.desktop")
        
        sleep(5)
        super(SwitcherTests, self).setUp()
        
        self.server = Switcher()

    def tearDown(self):
        call(["killall", "gcalctool"])
        call(["killall", "gucharmap"])
        super(SwitcherTests, self).tearDown()
        sleep(1)

    def test_switcher_move_next(self):
        self.set_timeout_setting(False)
        sleep(1)

        self.server.initiate()
        sleep(.2)
        
        start = self.server.get_selection_index()
        self.server.next_icon()
        sleep(.2)
        
        end = self.server.get_selection_index()
        self.server.terminate()
        
        self.assertThat(start, NotEquals(0))
        self.assertThat(end, Equals(start+1))
        self.set_timeout_setting(True)
    
    def test_switcher_move_prev(self):
        self.set_timeout_setting(False)
        sleep(1)

        self.server.initiate()
        sleep(.2)
        
        start = self.server.get_selection_index()
        self.server.previous_icon()
        sleep(.2)
        
        end = self.server.get_selection_index()
        self.server.terminate()
        
        self.assertThat(start, NotEquals(0))
        self.assertThat(end, Equals(start-1))
        self.set_timeout_setting(True)
