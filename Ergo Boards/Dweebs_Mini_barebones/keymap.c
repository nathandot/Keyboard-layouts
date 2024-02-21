/*	Nathan Steward 3/31/2021 Rev 1.0.1

    ::IMPORTANT::
        - use test env for compile "https://github.com/doesntfazer/qmk_firmware/"

	TODO:
		- fix MOBA and FPS layer
        - reassign bracket keys to something on base/lower/raise layer
        - find happy medium between planck and minidox

    SOFTWARE:
        - figure out compatibility issues for merging branch
          code with latest QMK firmware to take advantage of
          latest optimizations

	CHANGELOG:
		- Rev 1.0.0
            - pull from altered demo keymap
            - initial setup of MOBA and FPS layers
            - arrow cluster set under right hand, feels comfortable
        - Rev 1.0.1
            - added visual representation of MOBA and FPS layers
        - Rev 1.0.2
            - reverted LOWER location to standard
            - added Backspace/Enter to right thumb
            - fixed MOBA and FPS layouts with null keys
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
 * |  Tab |   Q  |   W  |   E  |   R  |   T  | PgUp |    | Home |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------|    |------+------+------+------+------+------+------|
 * |  Esc |   A  |   S  |   D  |   F  |   G  | PgDn |    | End  |   H  |   J  |   K  |   L  |   ;  |   '  |
 * |------+------+------+------+------+------+------'    `------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |                  |   N  |   M  |   ,  |   .  |   /  | Enter|
 * `-----------------------------------------'                  `-----------------------------------------'
 *                   ,---------------------------.          ,---------------------------.
 *                   |  Alt | Ctrl | LOWER|      |          |      | RAISE|  Gui |XXXXXX|
 *                   `--------------------| Space|          | Bksp |--------------------'
 *                                        |      |          |      |
 *                                        `------'          `------'
 */
[_QWERTY] = LAYOUT(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_PGUP,          KC_HOME, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_PGDN,          KC_END,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,  \
                               KC_LALT, KC_LCTL, LOWER,   KC_SPACE,         KC_BSPC, RAISE,   KC_LGUI, XXXXXXX  \
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
 *                   `--------------------|      |          | Enter|--------------------'
 *                                        |      |          |      |
 *                                        `------'          `------'
 */
[_LOWER] = LAYOUT(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, XXXXXXX,          XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
    KC_DEL,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, KC_UNDS, KC_EQL,  KC_LBRC, KC_RBRC, _______, \
                               _______, _______, _______, _______,          KC_ENT,  _______, _______, _______  \
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

/* Adjust
 *
 * ,------------------------------------------------.    ,------------------------------------------------.
 * |XXXXXX|  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |    |XXXXXX|XXXXXX|XXXXXX|XXXXXX| FPSW | MOSW |XXXXXX|
 * |------+------+------+------+------+------+------|    |------+------+------+------+------+------+------|
 * |  Del |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |    |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|
 * |------+------+------+------+------+------+------'    `------+------+------+------+------+------+------|
 * |      | RESET|XXXXXX|XXXXXX|XXXXXX|XXXXXX|                  |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|      |
 * `-----------------------------------------'                  `-----------------------------------------'
 *                   ,---------------------------.          ,---------------------------.
 *                   |      |      |      |      |          |      |      |      |      |
 *                   `--------------------|      |          |      |--------------------'
 *                                        |      |          |      |
 *                                        `------'          `------'
 */
[_ADJUST] =  LAYOUT(
    XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, FPSW,    MOSW,    XXXXXXX, \
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    _______, RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
                               _______, _______, _______, _______,          _______, _______, _______, _______  \
),

/* MOBA
 *
 * ,------------------------------------------------.    ,------------------------------------------------.
 * |XXXXXX|   H  |   J  |   K  |   L  |   F  |XXXXXX|    |XXXXXX|XXXXXX|XXXXXX|XXXXXX| FPSW | QWSW |XXXXXX|
 * |------+------+------+------+------+------+------|    |------+------+------+------+------+------+------|
 * |XXXXXX|   Q  |   W  |   E  |   R  |   T  |XXXXXX|    |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|
 * |------+------+------+------+------+------+------'    `------+------+------+------+------+------+------|
 * |XXXXXX|   B  |   P  |   G  |   4  |   D  |                  |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|
 * `-----------------------------------------'                  `-----------------------------------------'
 *                   ,---------------------------.          ,---------------------------.
 *                   |XXXXXX|   Y  |  Tab |      |          |      |XXXXXX|XXXXXX|XXXXXX|
 *                   `--------------------| Space|          |XXXXXX|--------------------'
 *                                        |      |          |      |
 *                                        `------'          `------'
 */
[_MOBA] = LAYOUT(
    XXXXXXX, KC_H,    KC_J,    KC_K,    KC_L,    KC_F,    XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, FPSW,    QWSW,    XXXXXXX, \
    XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, KC_B,    KC_P,    KC_G,    KC_4,    KC_D,                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                               XXXXXXX, KC_Y,    KC_TAB,  KC_SPC,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
),

//TODO
/* FPS
 *
 * ,------------------------------------------------.    ,------------------------------------------------.
 * |  Tab |   Q  |   W  |   E  |   R  |   T  |  F1  |    |XXXXXX|XXXXXX|XXXXXX|XXXXXX| QWSW | MOSW |XXXXXX|
 * |------+------+------+------+------+------+------|    |------+------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   M  |    |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|
 * |------+------+------+------+------+------+------'    `------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |                  |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|
 * `-----------------------------------------'                  `-----------------------------------------'
 *                   ,---------------------------.          ,---------------------------.
 *                   |  Esc |  Alt | Space|      |          |      |XXXXXX|XXXXXX|XXXXXX|
 *                   `--------------------|XXXXXX|          |XXXXXX|--------------------'
 *                                        |      |          |      |
 *                                        `------'          `------'
 */
[_FPS] = LAYOUT(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_F1,            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QWSW,    MOSW,    XXXXXXX, \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_M,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                               KC_ESC,  KC_LALT, KC_SPC,  XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
)
};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
