/* Copyright 202 Kevin Frei <kevinfrei@hotmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

// define the layers for the macropad
#define LY_MED  0
#define LY_PAT  1
#define SEL_BT  2
#define SEL_MSP 3
#define LY_SPD  4
#define LY_BR   5

enum my_keycodes {
    mute_gc = SAFE_RANGE,   
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case mute_gc:
      if (record->event.pressed) {
        // when keycode mute_gc is pressed
        register_code(KC_LCTRL); // press the left control (this will be kept down during the keypress)
        register_code(KC_D); // press the d key (this will be kept down during the keypress)
      } else {
        // when keycode mute_gc is released
        unregister_code(KC_LCTRL); // release the left control
        unregister_code(KC_D); // release the d key
      }
      return false; // Skip all further processing of this key
    default:
      return true; // Process all other keycodes normally
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[LY_MED] =  LAYOUT(mute_gc, KC_MPLY, LT(LY_PAT,KC_MNXT)),
[LY_PAT] =  LAYOUT(RGB_RMOD, RGB_MOD, KC_TRNS),
};
