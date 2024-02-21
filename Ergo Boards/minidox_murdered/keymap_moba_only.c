/*	Nathan Steward 12/8/2021 Rev 0.0.0
	CHANGELOG:
		- Rev 0.0.0
            - branch for MOBA-only right hand macropad
            - cleared all unneeded code
*/

#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum minidox_layers {
  _MOBA,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*  ,----------------------------------.
    |   H  |   J  |   K  |   L  |   F  |
    |------+------+------+------+------|
    |   Q  |   W  |   E  |   R  |   T  |
    |------+------+------+------+------|
    |   B  |   P  |   G  |   4  |   D  |
    `----------------------------------'
                     ,--------------------.
                     |   Y  |  Tab |      |
                     `-------------| Space|
                                   |      |
                                   `------'   */
[_MOBA] =  LAYOUT(
  KC_H,    KC_J,    KC_K,    KC_L,    KC_F,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  KC_B,    KC_P,    KC_G,    KC_4,    KC_D,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
                    KC_Y,    KC_TAB,  KC_SPC,        XXXXXXX, XXXXXXX, XXXXXXX                   \
)
};
