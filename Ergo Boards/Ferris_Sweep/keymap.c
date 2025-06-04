/*	Nathan Steward 3/5/2021 Rev 1.3.0

	TODO:
		- TBA

	CHANGELOG:
		- Rev 1.0.0
            - initial setup
            - attempted to port from gray Planck as close as possible
            - League Layer to mimic Razer Tartarus
        - Rev 1.2.0
            - added new layer for FPS games
            - renamed _LEAGUE layer to _MOBA
            - moved defines for layers to enum
            - renamed enums from "custom_*" to "minidox_*"
        - Rev 1.2.1
            - moved arrow cluster from left hand RAISE layer to right hand
                - should reflect 'Dweebs Mini' arrow cluster
                - forced PGUP/PGDN and HOME/END keys to move as well
        -rev 1.3.0
            - homerow mod additions GASC order with _ADJUST layer changes
            - remove _MOBA and _FPS as they were underused
            - updates to keycode definitions with latest rev of QMK
              - update RESET keycode to QK_BOOT
              - update layer_state_set_user data type from uint32_t to layer_state_t
              - update state data type from uint32_t to layer_state_t
*/

//CURRENTLY TESTING

#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum fsweep_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum fsweep_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

// Defines for home row Mod-Tap, GASC Ordering
#define GUI_A LGUI_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define SFT_D LSFT_T(KC_D)
#define CTL_F LCTL_T(KC_F)

#define CTL_J LCTL_T(KC_J)
#define SFT_K LSFT_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define GUI_CLN LGUI_T(KC_SCLN)


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
 * | GUI/A| ALT/S| SFT/D| CTL/F|   G  |           |   H  | CTL/J| SFT/K| ALT/L| GUI/;|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *                          ,-------------.    ,------,------.
 *                          | LOWER|      |    |      | RAISE|
 *                          `------| Space|    |BckSpc|------'
 *                                 |      |    |      |
 *                                 `------'    `------'
 */
[_QWERTY] = LAYOUT(
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   \
  GUI_A,   ALT_S,   SFT_D,   CTL_F,   KC_G,         KC_H,    CTL_J,   SFT_K,   ALT_L,   GUI_CLN,\
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,\
                             LOWER, KC_SPC,         KC_BSPC, RAISE,                             \
),

/* Lower
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |           |   ^  |   &  |   *  |   (  |   )  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Esc |      |      |      |XXXXXX|           |   '  |   -  |   +  |   {  |   }  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Del |XXXXXX|XXXXXX|  Tab |XXXXXX|           |   \  |   _  |   =  |   [  |   ]  |
 * `----------------------------------'           `----------------------------------'
 *                          ,-------------.    ,------,------.
 *                          |      |      |    |      |      |
 *                          `------|      |    | Enter|------.
 *                                 |      |    |      |
 *                                 `------'    `------'
 */
[_LOWER] = LAYOUT(
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,\
  KC_ESC,  _______, _______, _______, XXXXXXX,      KC_QUOT, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR,\
  KC_DEL,  XXXXXXX, XXXXXXX, KC_TAB,  XXXXXXX,      KC_BSLS, KC_UNDS, KC_EQL,  KC_LBRC, KC_RBRC,\
                             _______, _______,      KC_ENT,  _______,                           \
),

/* Raise
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |           |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|           | PgUp | Home |  Up  | End  |XXXXXX|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |XXXXXX|   `  |XXXXXX|XXXXXX|XXXXXX|           | PgDn | Left | Down |Right |XXXXXX|
 * `----------------------------------'           `----------------------------------'
 *                          ,-------------.    ,------,------.
 *                          |      |      |    |      |      |
 *                          `------|      |    |      |------.
 *                                 |      |    |      |
 *                                 `------'    `------'
 */
[_RAISE] = LAYOUT(
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      KC_PGUP, KC_HOME, KC_UP,   KC_END,  XXXXXXX,\
  XXXXXXX, KC_GRV,  XXXXXXX, XXXXXXX, XXXXXXX,      KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT,XXXXXXX,\
                             _______, _______,      _______, _______,                           \
),

/* Adjust (Lower + Raise)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  F7  |  F8  |  F9  |  F10 |  F11 |           |  F12 |XXXXXX|XXXXXX|XXXXXX|XXXXXX|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |           |  F6  |XXXXXX|XXXXXX|Taskmg|caltde|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | Reset|XXXXXX|XXXXXX|XXXXXX|XXXXXX|           |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|
 * `----------------------------------'           `----------------------------------'
 *                          ,-------------.    ,------,------.
 *                          |      |      |    |      |      |
 *                          `------|XXXXXX|    |XXXXXX|------.
 *                                 |      |    |      |
 *                                 `------'    `------'
 */
[_ADJUST] =  LAYOUT(
  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,       KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   XXXXXXX, XXXXXXX, TSKMGR,  CALTDEL,\
  QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
                             _______, XXXXXXX,      XXXXXXX, _______,                           \
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
