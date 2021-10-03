/* Mouse jiggler stuff pulled from https://github.com/DIYCharles/MouseJiggler

 Copyright 2017 Paul James (paul@peej.co.uk)
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

#define SPAM_DELAY 500  // 500 milliseconds between spams
bool mouse_jiggle_mode = false;
uint32_t spam_timer = 0;

//MAKE SURE THESE ARE INCLUDED
#include "artsey.h"
#include "keymap_combo.h"
#include "artsey.c"



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * ,----------------------------------------   ----------------------------------------.
 * |  Tab  |  Esc  |   (   |   {   |   [   |   |   ]   |   }   |   )   |   '   | BkSp  |
 * |   ~   |   `   |   <   |   _   |   -   |   |   +   |   =   |   >   |   \   |  Del  |
 * |-------+-------+-------+-------+-------+   |-------+-------+-------+-------+-------|
 * |   Q   |   W   |   E   |   R   |   T   |   |   Y   |   U   |   I   |   O   |   P   |
 * |   1   |   2   |   3   |   4   |   5   |   |   6   |   7   |   8   |   9   |   0   |
 * |-------+-------+-------+-------+-------+   |-------+-------+-------+-------+-------|
 * |   A   |   S   |   D   |   F   |   G   |   |   H   |   J   |   K   |   L   | Enter |
 * |  F1   |  F2      F3   |  F4   |  F5   |   | PgUp  | Home  |  Up   |  End  |   ;   |
 * |-Shift-+-------+-------+-------+-------+   |-------+-------+-------+-------+-------|
 * |   Z   |   X   |   C   |   V   |   B   |   |   N   |   M   |   ,   |   .   |   /   |
 * |  F6   |  F7   |  F8   |  F9   |  F10  |   | PgDn  | Left  | Down  | Right |       |
 * `-Shift---Layer-+-------+-------+-------+   |-------+-------+-------+---------Layer-'
 *                 | Ctrl  |  Gui  |  Alt  |   | Space | Layer | Shift |
 *                 |       |       |       |   | Funct |       |       |
 *                 `------------------------   `-Layer-----------------'
 */

[_A_BASE] = LAYOUT_split_4x5_3(
    A_BASE_S, A_BASE_T, A_BASE_R, A_BASE_A, KC_MINS,         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    A_BASE_O,A_BASE_I,A_BASE_Y,A_BASE_E,OSM(MOD_LSFT),       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    OSM(MOD_LCTL),KC_AT,KC_DEL,KC_EQL,KC_TAB,                KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    TG(_FN), KC_NO, MOUSEJIGGLERMACRO, KC_NO, CLEARALL,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                DF(MACROLAYER), KC_ENT, KC_SPACE,            KC_NO, KC_NO, KC_NO
),

[_A_NUM] = LAYOUT_split_4x5_3(
    A_NUM_S, A_NUM_T, A_NUM_R, A_NUM_A, KC_TRNS,         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    A_NUM_O,A_NUM_I,A_NUM_Y,A_NUM_E,KC_TRNS,             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_5,KC_4,KC_3,KC_2,KC_1,                            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_0, KC_9, KC_8, KC_7, KC_6,                        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                KC_TRNS, KC_TRNS, KC_TRNS,               KC_NO, KC_NO, KC_NO
),

[_A_NAV] = LAYOUT_split_4x5_3(
    A_NAV_S, A_NAV_T, A_NAV_R, A_NAV_A, KC_TRNS,             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    A_NAV_O,A_NAV_I,A_NAV_Y,A_NAV_E,KC_TRNS,                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                KC_TRNS, KC_TRNS, KC_TRNS,                   KC_NO, KC_NO, KC_NO
),

[_A_SYM] = LAYOUT_split_4x5_3(
    A_SYM_S, A_SYM_T, A_SYM_R, A_SYM_A, KC_TRNS,             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    A_SYM_O,A_SYM_I,A_SYM_Y,A_SYM_E,KC_TRNS,                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                KC_TRNS, KC_TRNS, KC_TRNS,                   KC_NO, KC_NO, KC_NO
),

[_A_BRAC] = LAYOUT_split_4x5_3(
    A_BRAC_S, A_BRAC_T, A_BRAC_R, A_BRAC_A, KC_TRNS,             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    A_BRAC_O,A_BRAC_I,A_BRAC_Y,A_BRAC_E,KC_TRNS,                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                KC_TRNS, KC_TRNS, KC_TRNS,                   KC_NO, KC_NO, KC_NO
),

[_A_MOU] = LAYOUT_split_4x5_3(
    A_MOU_S, A_MOU_T, A_MOU_R, A_MOU_A, KC_TRNS,             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    A_MOU_O,A_MOU_I,A_MOU_Y,A_MOU_E,KC_TRNS,                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                KC_TRNS, KC_TRNS, KC_TRNS,                   KC_NO, KC_NO, KC_NO
),

[_A_CUSTOM] = LAYOUT_split_4x5_3(
    A_CUSTOM_S, A_CUSTOM_T, A_CUSTOM_R, A_CUSTOM_A, KC_TRNS,             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    A_CUSTOM_O,A_CUSTOM_I,A_CUSTOM_Y,A_CUSTOM_E,KC_TRNS,                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                KC_TRNS, KC_TRNS, KC_TRNS,                   KC_NO, KC_NO, KC_NO
),

[_FN] = LAYOUT_split_4x5_3(
    KC_F5,KC_F4,KC_F3,KC_F2,KC_F1,                            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_F10, KC_F9, KC_F8, KC_F7, KC_F6,                       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_F15, KC_F14, KC_F13, KC_F12, KC_F11,                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                KC_TRNS, KC_TRNS, KC_TRNS,                    KC_NO, KC_NO, KC_NO
),

[MACROLAYER] = LAYOUT_split_4x5_3(
    HEAD1, HEAD2, HEAD3, HEAD4,TO(MACROLAYER2),                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    BODY1,BODY2,BODY3,BODY4,APPLYSTYLES,                        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    LVL1, LVL3,NOTE,WARN,INT,                                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    QRGB1, QRGB2, QRGB3, STRONG, SUBEM,                         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
             DF(_A_BASE), KC_TRNS, KC_TRNS,                     KC_NO, KC_NO, KC_NO
),

[MACROLAYER2] = LAYOUT_split_4x5_3(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,TO(MACROLAYER),          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    TBLBOD1,TBLBOD2,TBLBOD3,TBLBOD4,KC_TRNS,                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    TBLLVL1, TBLLVL3,TBLNOTE,TBLWARN,CON,                       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    TBLQRGB1, TBLQRGB2, TBLQRGB3, KC_TRNS, KC_TRNS,             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
             KC_TRNS, KC_TRNS, KC_TRNS,                         KC_NO, KC_NO, KC_NO
),

};

void matrix_scan_user(void) {
  if (mouse_jiggle_mode) {
       if (timer_elapsed32(spam_timer) > SPAM_DELAY) {
    tap_code(KC_MS_UP);
    tap_code(KC_MS_DOWN);
    tap_code(KC_MS_LEFT);
    tap_code(KC_MS_RIGHT);
    tap_code(KC_MS_WH_UP);
    tap_code(KC_MS_WH_DOWN);
    spam_timer = timer_read32();
  } else {
 }} else {}
}


