# -*- Mode: Python; coding: utf-8; indent-tabs-mode: nil; tab-width: 4 -*-
# Copyright 2010 Canonical
# Author: Alex Launi
#
# This program is free software: you can redistribute it and/or modify it
# under the terms of the GNU General Public License version 3, as published
# by the Free Software Foundation.

from testtools.matchers import Equals, LessThan
from time import sleep

from autopilot.emulators.X11 import ScreenGeometry
from autopilot.emulators.unity.hud import HudController
from autopilot.tests import AutopilotTestCase
from os import remove

class HudTests(AutopilotTestCase):

    screen_geometry = ScreenGeometry()
    num_monitors = screen_geometry.get_num_monitors()

    if num_monitors == 1:
        scenarios = [
            ('Single Monitor, Launcher never hide', {'hud_monitor': 0, 'launcher_hide_mode': 0}),
            ('Single Monitor, Launcher autohide', {'hud_monitor': 0, 'launcher_hide_mode': 1}),
            ]
    else:
        scenarios = []
        for i in range(num_monitors):
            scenarios.append(('Monitor %d, Launcher never hide' % (i), {'hud_monitor': i, 'launcher_hide_mode': 0}))
            scenarios.append(('Monitor %d, Launcher autohide' % (i), {'hud_monitor': i, 'launcher_hide_mode': 1}))

    def setUp(self):
        super(HudTests, self).setUp()
        self.set_unity_option('launcher_hide_mode', self.launcher_hide_mode)
        self.screen_geometry.move_mouse_to_monitor(self.hud_monitor)
        sleep(0.5)
        self.hud = self.get_hud_controller()

    def tearDown(self):
        self.hud.ensure_hidden()
        super(HudTests, self).tearDown()

    def get_hud_controller(self):
        controllers = HudController.get_all_instances()
        self.assertEqual(1, len(controllers))
        return controllers[0]

    def get_num_active_launcher_icons(self):
        num_active = 0
        for icon in self.launcher.model.get_launcher_icons():
            if icon.quirk_active and icon.quirk_visible:
                num_active += 1
        return num_active

    def test_initially_hidden(self):
        self.assertFalse(self.hud.visible)

    def reveal_hud(self):
        self.hud.toggle_reveal()
        for counter in range(10):
            sleep(1)
            if self.hud.visible:
                break

        self.assertTrue(self.hud.visible, "HUD did not appear.")

        (x, y, w, h) = self.hud.get_geometry()
        self.assertTrue(self.screen_geometry.is_rect_on_monitor(self.hud_monitor, x, y, w, h))

    def test_no_initial_values(self):
        self.reveal_hud()
        self.assertThat(self.hud.num_buttons, Equals(0))
        self.assertThat(self.hud.selected_button, Equals(0))

    def test_check_a_values(self):
        self.reveal_hud()
        self.keyboard.type('a')
        # Give the HUD a second to get values.
        sleep(1)
        self.assertThat(self.hud.num_buttons, Equals(5))
        self.assertThat(self.hud.selected_button, Equals(1))

    def test_up_down_arrows(self):
        self.reveal_hud()
        self.keyboard.type('a')
        # Give the HUD a second to get values.
        sleep(1)
        self.keyboard.press_and_release('Down')
        self.assertThat(self.hud.selected_button, Equals(2))
        self.keyboard.press_and_release('Down')
        self.assertThat(self.hud.selected_button, Equals(3))
        self.keyboard.press_and_release('Down')
        self.assertThat(self.hud.selected_button, Equals(4))
        self.keyboard.press_and_release('Down')
        self.assertThat(self.hud.selected_button, Equals(5))
        # Down again stays on 5.
        self.keyboard.press_and_release('Down')
        self.assertThat(self.hud.selected_button, Equals(5))
        self.keyboard.press_and_release('Up')
        self.assertThat(self.hud.selected_button, Equals(4))
        self.keyboard.press_and_release('Up')
        self.assertThat(self.hud.selected_button, Equals(3))
        self.keyboard.press_and_release('Up')
        self.assertThat(self.hud.selected_button, Equals(2))
        self.keyboard.press_and_release('Up')
        self.assertThat(self.hud.selected_button, Equals(1))
        # Up again stays on 1.
        self.keyboard.press_and_release('Up')
        self.assertThat(self.hud.selected_button, Equals(1))

    def test_slow_tap_not_reveal_hud(self):
        self.hud.toggle_reveal(tap_delay=0.3)
        sleep(1)
        self.assertFalse(self.hud.visible)

    def test_alt_f4_doesnt_show_hud(self):
        self.start_app('Calculator')
        sleep(1)
        # Do a very fast Alt+F4
        self.keyboard.press_and_release("Alt+F4", 0.05)
        sleep(1)
        self.assertFalse(self.hud.visible)

    def test_reveal_hud_with_no_apps(self):
        """Hud must show even with no visible applications."""
        self.keyboard.press_and_release("Ctrl+Alt+d")
        self.addCleanup(self.keyboard.press_and_release, "Ctrl+Alt+d")
        sleep(1)

        self.hud.toggle_reveal()
        sleep(1)
        self.assertTrue(self.hud.visible)

        self.hud.toggle_reveal()
        sleep(1)
        self.assertFalse(self.hud.visible)

    def test_multiple_hud_reveal_does_not_break_launcher(self):
        """Multiple Hud reveals must not cause the launcher to set multiple
        apps as active.

        """
        # We need an app to switch to:
        self.start_app('Character Map')
        # We need an application to play with - I'll use the calculator.
        self.start_app('Calculator')
        sleep(1)

        # before we start, make sure there's zero or one active icon:
        num_active = self.get_num_active_launcher_icons()
        self.assertThat(num_active, LessThan(2), "Invalid number of launcher icons active before test has run!")

        # reveal and hide hud several times over:
        for i in range(3):
            self.hud.ensure_visible()
            sleep(0.5)
            self.hud.ensure_hidden()
            sleep(0.5)

        # click application icons for running apps in the launcher:
        icon = self.launcher.model.get_icon_by_tooltip_text("Character Map")
        self.launcher.get_launcher_for_monitor(self.hud_monitor).click_launcher_icon(icon)

        # see how many apps are marked as being active:
        num_active = self.get_num_active_launcher_icons()
        self.assertLessEqual(num_active, 1, "More than one launcher icon active after test has run!")

    def test_restore_focus(self):
        """Ensures that once the hud is dismissed, the same application
        that was focused before hud invocation is refocused
        """
        self.start_app("Calculator")
        calc = self.get_app_instances("Calculator")
        self.assertThat(len(calc), Equals(1))
        calc = calc[0]

        # first ensure that the application has started and is focused
        self.assertEqual(calc.is_active, True)

        self.hud.toggle_reveal()
        sleep(1)
        self.hud.toggle_reveal()
        sleep(1)

        # again ensure that the application we started is focused
        self.assertEqual(calc.is_active, True)

        #test return
        self.hud.toggle_reveal()
        sleep(1)

        #test return
        self.hud.toggle_reveal()
        sleep(1)
        self.keyboard.press_and_release('Return')
        sleep(1)

        self.assertEqual(calc.is_active, True)

    def test_gedit_undo(self):
        """Test undo in gedit"""
        """Type "0 1" into gedit."""
        """Activate the Hud, type "undo" then enter."""
        """Save the file in gedit and close gedit."""
        """Read the saved file. The content should be "0 "."""

        self.addCleanup(remove, '/tmp/autopilot_gedit_undo_test_temp_file.txt')
        self.start_app('Text Editor', files=['/tmp/autopilot_gedit_undo_test_temp_file.txt'])

        sleep(1)
        self.keyboard.type("0")
        self.keyboard.type(" ")
        self.keyboard.type("1")

        self.hud.toggle_reveal()
        sleep(1)

        self.keyboard.type("undo")
        self.keyboard.press_and_release('Return')
        sleep(1)

        self.keyboard.press_and_release("Ctrl+s")
        sleep(1)

        contents = open("/tmp/autopilot_gedit_undo_test_temp_file.txt").read().strip('\n')
        self.assertEqual("0 ", contents)

    def test_hud_dont_change_launcher_status(self):
        launcher_shows_pre = self.launcher.get_launcher_for_monitor(self.hud_monitor).is_showing()
        sleep(.25)

        self.reveal_hud()
        sleep(1)

        launcher_shows_post = self.launcher.get_launcher_for_monitor(self.hud_monitor).is_showing()
        self.assertEqual(launcher_shows_pre, launcher_shows_post)

