/*
This is the keymap for the keyboard

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2017 Art Ortenburger

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
  _DVORAK,
  _COLEMAK,
  _RAISE,
  _LOWER,
  _FUNC
};

#define COLEMAK PDF(_COLEMAK)
#define DVORAK PDF(_DVORAK)
#define CTL_SPC CTL_T(KC_SPC)
#define ALT_DEL ALT_T(KC_DEL)
#define C_A_DEL LCA(KC_DEL)
#define PASTEVL LCS(KC_V)
#define LOW_F13 LT(_LOWER, KC_F13)
#define RSE_F14 LT(_RAISE, KC_F14)
#define FNC_ESC LT(_FUNC, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Dvorak
   * ,-----------------------------------------------.                                      ,-----------------------------------------------.
   * |Fnc/Esc|  ' "  |  , <  |  . >  |   P   |   Y   |                                      |   F   |   G   |   C   |   R   |   L   | Bspc  |
   * |-------+-------+-------+-------+-------+-------|                                      |-------+-------+-------+-------+-------+-------|
   * |  Tab  |   A   |   O   |   E   |   U   |   I   |                                      |   D   |   H   |   T   |   N   |   S   | Enter |
   * |-------+-------+-------+-------+-------+-------|                                      |-------+-------+-------+-------+-------+-------|
   * | Shift |  ; :  |   Q   |   J   |   K   |   X   | ,---------------.  ,---------------. |   B   |   M   |   W   |   V   |   Z   | Shift |
   * `-----------------------------------------------' |  Home |  End  |  |  PgUp |  PgDn | `-----------------------------------------------'
   *                                           ,-------+-------+-------.  ,-------+-------+-------.
   *                                           |Low/F13|Alt/Del|Windows|  |PastVlu|Ctl/Spc|Rai/F14|
   *                                           `-----------------------'  `-----------------------'
   */ 
   [_DVORAK] = LAYOUT(
    FNC_ESC, KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                                                                   KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
    KC_TAB,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,             KC_HOME, KC_END,           KC_PGUP, KC_PGDN,          KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT,
    KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    LOW_F13, ALT_DEL, KC_LGUI,          PASTEVL, CTL_SPC, RSE_F14, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT
  ),

  /* Colemak
   * ,-----------------------------------------------.                                      ,-----------------------------------------------.
   * |Fnc/Esc|   Q   |   W   |   F   |   P   |   G   |                                      |   J   |   L   |   U   |   Y   |  ; :  | Bspc  |
   * |-------+-------+-------+-------+-------+-------|                                      |-------+-------+-------+-------+-------+-------|
   * |  Tab  |   A   |   R   |   S   |   T   |   D   |                                      |   H   |   N   |   E   |   I   |   O   | Enter |
   * |-------+-------+-------+-------+-------+-------|                                      |-------+-------+-------+-------+-------+-------|
   * | Shift |   Z   |   X   |   C   |   V   |   B   | ,---------------.  ,---------------. |   K   |   M   |  , <  |  . >  |  / ?  | Shift |  should (/ ?) change to (' ") ?
   * `-----------------------------------------------' |  Home |  End  |  |  PgUp |  PgDn | `-----------------------------------------------'
   *                                           ,-------+-------+-------.  ,-------+-------+-------.
   *                                           |Low/F13|Alt/Del|Windows|  |PastVlu|Ctl/Spc|Rai/F14|
   *                                           `-----------------------'  `-----------------------'
   */ 
  [_COLEMAK] = LAYOUT(
    FNC_ESC, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                                                                   KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    KC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,             KC_HOME, KC_END,           KC_PGUP, KC_PGDN,          KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    LOW_F13, ALT_DEL, KC_LGUI,          PASTEVL, CTL_SPC, RSE_F14, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT
  ),

  /* Raise
   * ,-----------------------------------------------.                                      ,-----------------------------------------------.
   * |       |       |       |       |       |       |                                      |   *   |   7   |   8   |   9   |   =   |  Del  |
   * |-------+-------+-------+-------+-------+-------|                                      |-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |       |       |                                      |   +   |   4   |   5   |   6   |   -   |       |
   * |-------+-------+-------+-------+-------+-------|                                      |-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |       |       | ,---------------.  ,---------------. |   0   |   1   |   2   |   3   |   /   |       |
   * `-----------------------------------------------' |       |       |  |       |       | `-------+-------+-------------------------------'
   *                                           ,-------+-------+-------.  ,-------+-------+-------.
   *                                           |       |       |       |  |       |       |       |
   *                                           `-----------------------'  `-----------------------'
   */
  [_RAISE] = LAYOUT(
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                                                KC_ASTR, KC_7,    KC_8,    KC_9,    KC_EQL,  KC_DEL,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          _______, _______,          _______, _______,          KC_PLUS, KC_4,    KC_5,    KC_6,    KC_MINS, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______,          _______, _______, _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_SLSH, _______
  ),

  /* Lower
   * ,-----------------------------------------------.                                      ,-----------------------------------------------.
   * |       |   `   |   [   |   ]   |   %   |   &   |                                      |       |       |   Up  |       |   ^   |       |
   * |-------+-------+-------+-------+-------+-------|                                      |-------+-------+-------+-------+-------+-------|
   * |       |   @   |   (   |   )   |   _   |   |   |                                      |   $   |  Left |  Down | Right |   ~   |       |
   * |-------+-------+-------+-------+-------+-------|                                      |-------+-------+-------+-------+-------+-------|
   * |       |   !   |   {   |   }   |   ?   |   #   | ,---------------.  ,---------------. |       |       |       |       |   \   |       |
   * `-----------------------------------------------' |       |       |  |       |       | `-------+-------+-------------------------------'
   *                                           ,-------+-------+-------.  ,-------+-------+-------.
   *                                           |       |       |       |  |       |       |       |
   *                                           `-----------------------'  `-----------------------'
   */
  [_LOWER] = LAYOUT(
    _______, KC_GRV,  KC_LBRC, KC_RBRC, KC_PERC, KC_AMPR,                                                                XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, KC_CIRC, _______,
    _______, KC_AT,   KC_LPRN, KC_RPRN, KC_UNDS, KC_PIPE,          _______, _______,          _______, _______,          KC_DLR,  KC_LEFT, KC_DOWN, KC_RGHT, KC_TILD, _______,
    _______, KC_EXLM, KC_LCBR, KC_RCBR, KC_QUES, KC_HASH, _______, _______, _______,          _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS, _______
  ),

  /* Func
   * ,-----------------------------------------------.                                      ,-----------------------------------------------.
   * |       |       |       |       | Print |       |                                      |  F12  |   F7  |   F8  |   F9  |       |C+A+Del|
   * |-------+-------+-------+-------+-------+-------|                                      |-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |       |       |                                      |  F11  |   F4  |   F5  |   F6  |       |       |
   * |-------+-------+-------+-------+-------+-------|                                      |-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |       |       | ,---------------.  ,---------------. |  F10  |   F1  |   F2  |   F3  |       |       |
   * `-----------------------------------------------' |       |       |  |Colemak| Dvorak| `-------+-------+-------------------------------'
   *                                           ,-------+-------+-------.  ,-------+-------+-------.
   *                                           |       |       |       |  |       |       |       |
   *                                           `-----------------------'  `-----------------------'
   */
   [_FUNC] = LAYOUT(
    _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, XXXXXXX,                                                                KC_F12,  KC_F7,   KC_F8,   KC_F9,   XXXXXXX, C_A_DEL,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX,          COLEMAK, DVORAK,           KC_F11,  KC_F4,   KC_F5,   KC_F6,   XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, KC_F10,  KC_F1,   KC_F2,   KC_F3,   XXXXXXX, XXXXXXX
  )

};





