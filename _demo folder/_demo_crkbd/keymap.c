/*	Nathan Steward 3/5/2021 Rev 0.0.0

	TODO:
		- TBA

	CHANGELOG:
		- Rev 0.0.0
            - initial setup
*/



#include QMK_KEYBOARD_H

extern uint8_t is_master;

enum ckrbd_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _CODE
};
enum crkbd_keycodes {
  QWERTY = SAFE_RANGE

};

enum crkbd_keycodes {
  //
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------.                           ,-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                           |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------|                           |------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |                           |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|                           |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |                           |   N  |   M  |   ,  |   .  |  /   |      |
 * `---------------------------+------+------+------.             ,------+------+------+---------------------------'
 *                             | Gui  | Alt  |Space |             |Enter |Lower |Raise |
 *                             `--------------------'             `--------------------'
 */
[_QWERTY] = LAYOUT_split_3x6_3(\
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,\
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,\
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX,\
                                        KC_LGUI, KC_LALT, KC_SPC,  KC_ENT,  LOWER,   RAISE                                       \
),

/* Lower
* ,-----------------------------------------.                           ,-----------------------------------------.
* |   ~  |   !  |   @  |   #  |   $  |   %  |                           |   ^  |   &  |   *  |   (  |   )  |      |
* |------+------+------+------+------+------|                           |------+------+------+------+------+------|
* | Del  |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|                           |XXXXXX|   -  |   +  |   {  |   }  |  |   |
* |------+------+------+------+------+------|                           |------+------+------+------+------+------|
* |      |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|                           |XXXXXX|   _  |   =  |   [  |   ]  |      |
* `---------------------------+------+------+------.             ,------+------+------+---------------------------'
*                             |      |      |      |             |      |      |      |
*                             `--------------------'             `--------------------'
*/
[_LOWER] = LAYOUT_split_3x6_3(\
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,\
    KC_DEL,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,\
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_UNDS, KC_EQL,  KC_LBRC, KC_RBRC, _______,\
                                        _______, _______, _______, _______, _______, _______                                     \
),

/* Raise
 * ,-----------------------------------------.                           ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |                           |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                           |------+------+------+------+------+------|
 * | Del  |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|                           |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|  \   |
 * |------+------+------+------+------+------|                           |------+------+------+------+------+------|
 * |      |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|                           |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|      |
 * `---------------------------+------+------+------.             ,------+------+------+---------------------------'
 *                             |      |      |      |             |      |      |      |
 *                             `--------------------'             `--------------------'
 */
[_RAISE] = LAYOUT_split_3x6_3(\
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,\
    KC_DEL,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS,\
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,\
                                        _______, _______, _______, _______, _______, _______                                     \
),

/* Adjust
 * ,-----------------------------------------.                           ,-----------------------------------------.
 * |XXXXXX|  F7  |  F8  |  F9  |  F10 |  F11 |                           |  F12 |XXXXXX|XXXXXX|XXXXXX|XXXXXX|      |
 * |------+------+------+------+------+------|                           |------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |                           |  F6  |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|
 * |------+------+------+------+------+------|                           |------+------+------+------+------+------|
 * |      | Reset| Debug|XXXXXX|XXXXXX|XXXXXX|                           |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|      |
 * `---------------------------+------+------+------.             ,------+------+------+---------------------------'
 *                             |      |      |      |             |      |      |      |
 *                             `--------------------'             `--------------------'
 */
  [_ADJUST] = LAYOUT_split_3x6_3(\
    XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,                    KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,\
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
    _______, RESET,   DEBUG,   XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,\
                                        _______, _______, _______, _______, _______, _______                                     \
  )
};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void matrix_init_user(void) {
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    //matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
