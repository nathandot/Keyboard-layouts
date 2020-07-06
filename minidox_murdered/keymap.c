#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0u
#define _LOWER 1u
#define _RAISE 2u
#define _ADJUST 3u
#define _LEAGUE 4u

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  LEAGUE,
};

// Defines for layers
#define LOWER MO(_LOWER) //lower layer
#define RAISE MO(_RAISE) //raise layer

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  | Ctrl | LOWER|      |    |      | RAISE| Shift|
 *                  `-------------| Space|    |BckSpc|------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_QWERTY] = LAYOUT(
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   \
  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,\
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,\
                    KC_LCTL, LOWER, KC_SPC,         KC_BSPC, RAISE, OSM(MOD_LSFT)               \
),

/* Lower
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |           |   ^  |   &  |   *  |   (  |   )  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Esc |XXXXXX|XXXXXX|XXXXXX|XXXXXX|           |   '  |   -  |   +  |   {  |   }  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Del |XXXXXX|XXXXXX|XXXXXX|XXXXXX|           |   \  |   _  |   =  |   [  |   ]  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      |      |      |
 *                  `-------------|      |    | Enter|------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_LOWER] = LAYOUT(
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,\
  KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      KC_QUOT, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR,\
  KC_DEL,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      KC_BSLS, KC_UNDS, KC_EQL,  KC_LBRC, KC_RBRC,\
                    _______, _______, _______,      KC_ENT,  _______, _______                   \
),

/* Raise
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |           |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Tab | Left | Down |  Up  | Right|           |XXXXXX| PgUp | Home |XXXXXX|XXXXXX|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Ctrl|   `  |  GUI |  Alt |XXXXXX|           |XXXXXX| PgDn | End  |XXXXXX|XXXXXX|
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      |      |      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_RAISE] = LAYOUT(
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   \
  KC_TAB,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,      XXXXXXX, KC_PGUP, KC_HOME, XXXXXXX, XXXXXXX,\
  KC_LCTL, KC_GRV,  KC_LGUI, KC_LALT, XXXXXXX,      XXXXXXX, KC_PGDN, KC_END,  XXXXXXX, XXXXXXX,\
                    _______, _______, _______,      _______, _______, _______                   \
),

/* Adjust (Lower + Raise)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  F7  |  F8  |  F9  |  F10 |  F11 |           |  F12 |XXXXXX|XXXXXX|XXXXXX|LEAGUE|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |           |  F6  |XXXXXX|XXXXXX|Taskmg|caltde|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | Reset|XXXXXX|XXXXXX|XXXXXX|XXXXXX|           |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |XXXXXX|      |      |    |      |      |XXXXXX|
 *                  `-------------|XXXXXX|    |XXXXXX|------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_ADJUST] =  LAYOUT(
  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,       KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, DF(_LEAGUE),\
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   XXXXXXX, XXXXXXX, TSKMGR,  CALTDEL,\
  RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
                    XXXXXXX, _______, XXXXXXX,      XXXXXXX, _______, XXXXXXX                   \
),

/* League layer
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   H  |   J  |   K  |   L  |   F  |           |XXXXXX|XXXXXX|XXXXXX|XXXXXX|QWERTY|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Q  |   W  |   E  |   R  |   T  |           |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   B  |   P  |   G  |   4  |   D  |           |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |   Y  |  Tab |      |    |      |XXXXXX|XXXXXX|
 *                  `-------------| Space|    |XXXXXX|------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_LEAGUE] =  LAYOUT(
  KC_H,    KC_J,    KC_K,    KC_L,   KC_F,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF(_QWERTY),\
  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  KC_B,    KC_P,    KC_G,    KC_4,   KC_D,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
                    KC_Y,    KC_TAB, KC_SPC,        XXXXXXX, XXXXXXX, XXXXXXX                   \
)
};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
