/* Copyright 2020 cjcodell1
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

enum layers{
  _BASE,
  _NUM_SYM,
  _RGB,
};

// enum combo_events {
//   COMBO_BSPC,
//   COMBO_NUMBAK,
//   COMBO_TAB,
//   COMBO_ESC,
//   COMBO_DEL,
// };



enum {
    TD_QESC,
    TD_WTAB,
    TD_QUOTJ,
    TD_YSCLN,
    TD_ZMINS,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_QESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
    [TD_WTAB] = ACTION_TAP_DANCE_DOUBLE(KC_W, KC_TAB),
    [TD_QUOTJ] = ACTION_TAP_DANCE_DOUBLE(KC_J, KC_QUOT),
    [TD_YSCLN] = ACTION_TAP_DANCE_DOUBLE(KC_Y, KC_SCLN),
    [TD_ZMINS] = ACTION_TAP_DANCE_DOUBLE(KC_Z, KC_MINS),
};

#define KC_CA LCTL_T(KC_A)
#define KC_AS LALT_T(KC_R)
#define KC_GD LGUI_T(KC_S)
#define KC_SF LSFT_T(KC_T)
#define KC_SJ RSFT_T(KC_N)
#define KC_GK RGUI_T(KC_E)
#define KC_AL RALT_T(KC_I)
#define KC_CENT RCTL_T(KC_O)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_space(
  TD(TD_QESC),  TD(TD_WTAB), KC_F, KC_P,  KC_G, TD(TD_QUOTJ),  KC_L,   KC_U,  TD(TD_YSCLN), KC_BSPC,
  KC_CA, KC_AS, KC_GD, KC_SF, KC_D, KC_H, KC_SJ, KC_GK,   KC_AL,  KC_CENT,
  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B, KC_K, KC_M,  KC_COMM, KC_DOT, KC_ENT,
             LT(_NUM_SYM, KC_SPC),               KC_LSFT
  ),

  [_NUM_SYM] = LAYOUT_split_space(
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,     KC_0,
 KC_LEFT,  KC_DOWN, KC_UP, KC_RIGHT, MO(_RGB),  KC_EQUAL, KC_LEFT, KC_UP,   KC_DOWN, KC_RIGHT,
  KC_MINS, KC_LBRC, KC_RBRC, KC_BSLASH, KC_GRAVE, C(KC_PSCREEN), KC_DEL, KC_SCLN, KC_COLN, KC_SLSH,
                    KC_TRNS,                                     KC_TRNS
  ),

    [_RGB] = LAYOUT_split_space(
  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    RGB_RMOD,    RGB_HUD,    RGB_SAD,    RGB_VAD,
 KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_TRNS,  RGB_TOG, RGB_MOD, RGB_HUI,   RGB_SAI, RGB_VAI,
  KC_NO,    KC_NO,    KC_NO,    KC_NO,    RESET,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
                    KC_TRNS,                                     KC_TRNS
  ),

};

// #ifdef COMBO_ENABLE
// const uint16_t PROGMEM combo_bspc[] = {KC_O, KC_P, COMBO_END};
// const uint16_t PROGMEM combo_numbak[] = {KC_0, KC_9, COMBO_END};
// const uint16_t PROGMEM combo_tab[] = {KC_Q, KC_W, COMBO_END};
// const uint16_t PROGMEM combo_esc[] = {KC_E, KC_W, COMBO_END};
// const uint16_t PROGMEM combo_del[] = {KC_MINS, KC_EQL, COMBO_END};

// combo_t key_combos[COMBO_COUNT] = {
//   [COMBO_BSPC] = COMBO(combo_bspc,KC_BSPC),
//   [COMBO_NUMBAK] = COMBO(combo_numbak,KC_BSPC),
//   [COMBO_TAB] = COMBO(combo_tab,KC_TAB),
//   [COMBO_ESC] = COMBO(combo_esc,KC_ESC),
//   [COMBO_DEL] = COMBO(combo_del,KC_DEL),

// };
// #endif
