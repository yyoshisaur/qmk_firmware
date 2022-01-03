#include "solecito.h"

enum layers {
  _BASE,
  _LOWER,
  _ADJUST,
};

enum combos {
  UP_ESC,
  AS_TAB,
  JL_QUOT,
};

const uint16_t PROGMEM up_combo[] = {KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM as_combo[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM jl_combo[] = {KC_J, KC_L, COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
  [UP_ESC] = COMBO(up_combo, KC_ESC),
  [AS_TAB] = COMBO(as_combo, KC_TAB),
  [JL_QUOT] = COMBO(jl_combo, KC_QUOT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_BASE] = LAYOUT(
		KC_1, KC_2, KC_3, KC_4, KC_5,	KC_6, KC_7, KC_8, KC_9, KC_0,
		KC_Q, KC_W, KC_F, KC_P, KC_G, 	KC_J, KC_L, KC_U, KC_Y, KC_BSPC,
		KC_A, KC_R, KC_S, KC_T, KC_D, KC_MUTE, LCTL(LALT(KC_DEL)),	KC_H, KC_N, KC_E, KC_I, KC_O,
		MT(MOD_LCTL,KC_Z), MT(MOD_LALT,KC_X), KC_C, KC_V, KC_B,	LT(1,KC_SPC), KC_LSFT,	LT(2,KC_K), KC_M, KC_COMM, KC_DOT, KC_ENT
    ),

	[_LOWER] = LAYOUT(
		KC_ESC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC,
		KC_TAB, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SCLN,
		KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_LBRC, KC_TRNS, KC_TRNS, KC_RBRC, KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT,
		KC_MINS, KC_EQUAL, KC_BSLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SLSH
		),

	[_ADJUST] = LAYOUT(
		KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, 	KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
		KC_TRNS, KC_LGUI, KC_TRNS, LCTL(KC_PSCREEN), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_DOWN, KC_DEL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	    LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_TRNS, KC_MS_BTN1, KC_MS_BTN2,	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
		)
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_MS_WH_DOWN);
        } else {
            tap_code(KC_MS_WH_UP);
        }
    }
  return false;
}

