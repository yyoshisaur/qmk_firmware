/* Copyright 2021 qpockets
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
  _NAV,
  _MOU,

};

enum combo_events {
 COMBO_QUOT,
 COMBO_BSPC,

};

#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_quot[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM combo_bspc[] = {KC_9, KC_0, COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
  [COMBO_QUOT] = COMBO(combo_quot,KC_QUOT),
  [COMBO_BSPC] = COMBO(combo_bspc,KC_BSPC),

};
#endif


#define SNIP S(G(KC_S))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_default(
    KC_ESC,   KC_Q,    KC_W,    KC_F,   KC_P,   KC_G,   KC_DEL,  KC_J,   KC_L,   KC_U,    KC_Y,      KC_BSPC,
    KC_TAB,   KC_A,    KC_R,    KC_S,  KC_T,   KC_D,   KC_MUTE, KC_H,   KC_N,  KC_E,    KC_I,      KC_O,
    LCTL_T(KC_MINUS),   LALT_T(KC_Z),    KC_X,    KC_C,   KC_V,   KC_B,   KC_ENT,  KC_K,   KC_M,   KC_COMM, KC_DOT,    KC_ENT,
    SNIP, KC_LGUI, TG(2),  			LT(1,KC_SPC),    		KC_LSFT,		  LT(2,KC_PIPE), KC_LBRC, KC_RBRC
  ),

  [_NAV] = LAYOUT_default(
    KC_GRAVE, KC_1,   KC_2,   KC_3,  KC_4,   KC_5,   KC_SCLN,  KC_6,   KC_7,   KC_8,    KC_9,   KC_0,
    KC_TAB,  KC_LEFT,   KC_DOWN,   KC_UP,  KC_RIGHT,   KC_HOME,   KC_CAPS, KC_END,   KC_LEFT,  KC_UP,    KC_DOWN,   KC_RIGHT,
    KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_EQL,  KC_TRNS,   KC_TRNS,   KC_COMM, KC_TRNS, KC_SLSH,
    C(KC_PSCR),  KC_TRNS,  KC_TRNS,    		 KC_TRNS,   	 KC_TRNS, 		 KC_TRNS, KC_TRNS, KC_TRNS
  ),

 [_MOU] = LAYOUT_default(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,   KC_WH_L,    KC_MS_BTN1, KC_MS_UP, KC_MS_BTN2, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,   KC_MS_BTN3,    KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,   KC_WH_R,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,   KC_TRNS,    KC_TRNS,      KC_TRNS, KC_TRNS,   KC_TRNS,    KC_TRNS,      KC_TRNS
  ),

};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* left encoder */
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) { /* center encoder */
        switch(biton32(layer_state)){
        case 2:
            if (clockwise){
                tap_code(KC_WH_D);
            } else{
                tap_code(KC_WH_U);
            }
            break;
        case 1:
            if (clockwise){
                tap_code(KC_WH_R);
            } else{
                tap_code(KC_WH_L);
            }
            break;
        default:
            if (clockwise) {
               tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
            break;
         }
    }
	return true;
}


