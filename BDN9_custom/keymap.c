/* Copyright 2019 Danny Nguyen <danny@keeb.io>
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

 /*	Nathan Steward 8/18/2020 Rev. 1.0.0

 	TODO:
 		- TBA

 	CHANGELOG:
 		- Rev 1.0.0
         - initial setup for macropad
         - needs planning still

 */

#include QMK_KEYBOARD_H

static bool alt_lock_bit = false;

#define _BASE 0u
#define _FN_ONE 1u
#define _FN_TWO 2u

enum custom_keycodes {
    ALT_LOCK = SAFE_RANGE
};

#define FN_BASE DF(_BASE)
#define FN_ONE DF(_FN_ONE)
#define FN_TWO DF(_FN_TWO)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        | Knob 1: Vol Dn/Up |      | Knob 2: Page Dn/Up |
        | Press: Mute       | Home | Press: Play/Pause  |
        | Hold: Layer 2     | Up   | RGB Mode           |
        | Left              | Down | Right              |
     */
    [_BASE] = LAYOUT(
        KC_MUTE, FN_ONE,  FN_TWO,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_FN_ONE] = LAYOUT(
        ALT_LOCK,FN_BASE, FN_TWO,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_FN_TWO] = LAYOUT(
        KC_MUTE, FN_ONE,  FN_BASE,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX
    ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (layer_state == _BASE) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (layer_state == _FN_ONE){
        if (clockwise) {
            tap_code16(KC_TAB);
        } else {
            tap_code16(LSFT(KC_TAB));
        }
    }
}
// "KEY_LOCK_ENABLE = yes" must be set in rules.mk
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ALT_LOCK:
            if(alt_lock_bit == false) {
                tap_code16(KC_LOCK);
                tap_code16(KC_LALT);
                alt_lock_bit = true;
            }
            else {
                tap_code16(KC_LALT);
                alt_lock_bit = false;
            }
  }
  return true;
}
