/*	Nathan Steward 3/5/2021 Rev 0.0.0

    ::IMPORTANT::
        - use test env for compile "https://github.com/doesntfazer/qmk_firmware/"

	TODO:
		- add MOBA and FPS layer modifications
        - figure out arrow cluster design
        - reassign bracket keys to something on base/lower/raise layer
        - find happy medium between planck and minidox

	CHANGELOG:
		- Rev 0.0.0
            - initial setup/ test env for new features
*/



#include QMK_KEYBOARD_H

enum dweebs_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _MOBA,
    _FPS,
};

enum dweebs_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

// Defines for layers
#define LOWER MO(_LOWER) //lower layer
#define RAISE MO(_RAISE) //raise layer

#define QWSW DF(_QWERTY) //default layer set to _QWERTY
#define MOSW DF(_MOBA)   //default layer set to _MOBA
#define FPSW DF(_FPS)    //default layer set to _FPS

// Defines for task manager and such
// #define CALTDEL LCTL(LALT(KC_DEL)) //unused
// #define TSKMGR LCTL(LSFT(KC_ESC)) //unused

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,------------------------------------------------.    ,------------------------------------------------.
 * |  Tab |   Q  |   W  |   E  |   R  |   T  |XXXXXX|    |XXXXXX|   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------|    |------+------+------+------+------+------+------|
 * |  Esc |   A  |   S  |   D  |   F  |   G  |XXXXXX|    |XXXXXX|   H  |   J  |   K  |   L  |   ;  |   '  |
 * |------+------+------+------+------+------+------'    `------+------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |                  |   N  |   M  |   ,  |   .  |   /  | Enter|
 * `-----------------------------------------'                  `-----------------------------------------'
 *                   ,---------------------------.          ,---------------------------.
 *                   |  Gui | Ctrl |  Alt |      |          |      | RAISE|XXXXXX|XXXXXX|
 *                   `--------------------| Space|          | LOWER|--------------------'
 *                                        |      |          |      |
 *                                        `------'          `------'
 */
[_QWERTY] = LAYOUT(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX,          XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    XXXXXXX,          XXXXXXX, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,  \
                               KC_LGUI, KC_LCTL, KC_LALT, KC_SPACE,         LOWER,   RAISE,   XXXXXXX, XXXXXXX  \
),

/* Lower
 *
 * ,------------------------------------------------.    ,------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |XXXXXX|    |XXXXXX|   ^  |   &  |   *  |   (  |   )  |Backsp|
 * |------+------+------+------+------+------+------|    |------+------+------+------+------+------+------|
 * |  Del |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|    |XXXXXX|XXXXXX|   -  |   +  |   {  |   }  |   |  |
 * |------+------+------+------+------+------+------'    `------+------+------+------+------+------+------|
 * |      |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|                  |XXXXXX|   _  |   =  |   [  |   ]  |      |
 * `-----------------------------------------'                  `-----------------------------------------'
 *                   ,---------------------------.          ,---------------------------.
 *                   |      |      |      |      |          |      |      |      |      |
 *                   `--------------------|      |          |      |--------------------'
 *                                        |      |          |      |
 *                                        `------'          `------'
 */
[_LOWER] = LAYOUT(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, XXXXXXX,          XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
    KC_DEL,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, KC_UNDS, KC_EQL,  KC_LBRC, KC_RBRC, _______, \
                               _______, _______, _______, _______,          _______, _______, _______, _______  \
),

/* Raise
 *
 * ,------------------------------------------------.    ,------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |XXXXXX|    |XXXXXX|   6  |   7  |   8  |   9  |   0  |Backsp|
 * |------+------+------+------+------+------+------|    |------+------+------+------+------+------+------|
 * |  Del |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|    |XXXXXX|XXXXXX|XXXXXX|  Up  |XXXXXX|XXXXXX|   \  |
 * |------+------+------+------+------+------+------'    `------+------+------+------+------+------+------|
 * |      |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|                  |XXXXXX| Left | Down | Right|XXXXXX|      |
 * `-----------------------------------------'                  `-----------------------------------------'
 *                   ,---------------------------.          ,---------------------------.
 *                   |      |      |      |      |          |      |      |      |      |
 *                   `--------------------|      |          |      |--------------------'
 *                                        |      |          |      |
 *                                        `------'          `------'
 */
[_RAISE] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX,          XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
    KC_DEL,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, KC_BSLS, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, _______, \
                               _______, _______, _______, _______,          _______, _______, _______, _______  \
),

[_ADJUST] =  LAYOUT(
    XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, FPSW,    MOSW,    XXXXXXX, \
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    _______, RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
                               _______, _______, _______, _______,          _______, _______, _______, _______  \
),

//TODO
[_MOBA] = LAYOUT(
    XXXXXXX, KC_H,    KC_J,    KC_K,    KC_L,    KC_F,    XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, FPSW,    QWSW,    XXXXXXX, \
    XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, KC_B,    KC_P,    KC_G,    KC_4,    KC_D,                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                               XXXXXXX, KC_Y,    KC_TAB,  KC_SPC,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
),

//TODO
[_FPS] = LAYOUT(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_F1,            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QWSW,    MOSW,    XXXXXXX, \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_M,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                               KC_ESC,  KC_ALT,  KC_SPACE,XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
)
};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
