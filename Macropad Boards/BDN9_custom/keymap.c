/*	Nathan Steward 8/21/2020 Rev. 1.1.0

 	TODO:
 		DONE - blank 3-layer setup
        DONE - implement "sticky" alt tab on rotary encoder

 	CHANGELOG:
 		- Rev 1.0.0
            - initial setup for macropad
            - needs planning still
        - Rev 1.1.0
            - full implementation of working alt-tab/alt-sft-Tab
                - exits tabbed screen on rotary button press
 */

#include QMK_KEYBOARD_H

bool alt_lock_bit = false;

enum layers {
    _BASE   = 0,
    _FN_ONE = 1,
    _FN_TWO = 2
};

enum custom_keycodes {
    ALT_LOCK = SAFE_RANGE
};

#define FN_BASE TO(_BASE)
#define FN_ONE  TO(_FN_ONE)
#define FN_TWO  TO(_FN_TWO)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        | Knob 1: Vol Dn/Up |      | Knob 2: Page Dn/Up |
        | Press: Mute       | Home | Press: Play/Pause  |
        | Hold: Layer 2     | Up   | RGB Mode           |
        | Left              | Down | Right              |
     */
    [_BASE] = LAYOUT(
        KC_MUTE, FN_ONE,  FN_TWO,  \
        KC_F22,  KC_F23,  KC_F24,  \
        KC_F19,  KC_F20,  KC_F21   \
    ),
    [_FN_ONE] = LAYOUT(
        ALT_LOCK,FN_BASE, FN_TWO,  \
        XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX  \
    ),
    [_FN_TWO] = LAYOUT(
        XXXXXXX, FN_ONE,  FN_BASE, \
        XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX  \
    )
};

void encoder_update_user(uint8_t index, bool clockwise) {
    switch(biton32(layer_state)){
        case _BASE:
            if (clockwise) {
                tap_code(KC_VOLD);
                break;
            }
            else {
                tap_code(KC_VOLU);
                break;
            }
        case _FN_ONE:
            if (clockwise) {
                register_code(KC_LALT);
                register_code(KC_LSFT);
                tap_code(KC_TAB);
                unregister_code(KC_LSFT);
                break;
            } else {
                register_code(KC_LALT);
                tap_code(KC_TAB);
                break;
            }

    }
}
// "KEY_LOCK_ENABLE = yes" must be set in rules.mk
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ALT_LOCK:
            if(record->event.pressed){
                unregister_code(KC_LALT);
                break;
            }
    }
    return true;
}
