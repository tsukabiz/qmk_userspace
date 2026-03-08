#include QMK_KEYBOARD_H

// Layers
#define _DVORAK  0
#define _LOWER   1
#define _RAISE   2
#define _FUNC    3

// Custom Keys
#define FNC_ESC LT(_FUNC, KC_ESC)
#define LOW_F13 LT(_LOWER, KC_F13)
#define RSE_F14 LT(_RAISE, KC_F14)
#define CTL_SPC MT(MOD_LCTL, KC_SPC)
#define ALT_DEL MT(MOD_LALT, KC_DEL)
#define CTLALTD LCA(KC_DEL)
#define PASTEVL LCS(KC_V)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Dvorak
  * ,-----------------------------------------------. ,-----------------------------------------------.
  * |Fnc/Esc|  ' "  |  , <  |  . >  |   P   |   Y   | |   F   |   G   |   C   |   R   |   L   | Bspc  |
  * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
  * |  Tab  |   A   |   O   |   E   |   U   |   I   | |   D   |   H   |   T   |   N   |   S   | Enter |
  * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
  * | Shift |  ; :  |   Q   |   J   |   K   |   X   | |   B   |   M   |   W   |   V   |   Z   | Shift |
  * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------| 
  * |ScrShot|  Gui  | Home  |  End  |Low/F13|Alt/Del| |Ctl/Spc|Rse/F14|  P.Up | P.Down|  App  |PastVlu|
  * `-----------------------------------------------' `-----------------------------------------------' 
  */
  [_DVORAK] = LAYOUT(
    FNC_ESC, KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
    KC_TAB,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT,
    KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT,
    KC_PSCR, KC_LGUI, KC_HOME, KC_END,  LOW_F13, ALT_DEL, CTL_SPC, RSE_F14, KC_PGUP, KC_PGDN, KC_APP,  PASTEVL
  ),

/* Lower
  * ,-----------------------------------------------. ,-----------------------------------------------.
  * |       |   `   |   [   |   ]   |   %   |   &   | |       |       |  Up   |       |   ^   |       |
  * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
  * |       |   @   |   (   |   )   |   _   |   |   | |   $   | Left  |  Down | Right |   ~   |       |
  * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
  * |       |   !   |   {   |   }   |   ?   |   #   | |       |       |       |       |   \   |       |
  * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
  * |       |       |       |       |[Lower]|       | |       |       |       |       |       |       |
  * `-----------------------------------------------' `-----------------------------------------------'
  */
  [_LOWER] = LAYOUT(
    XXXXXXX, KC_GRV,  KC_LBRC, KC_RBRC, KC_PERC, KC_AMPR, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, KC_CIRC, XXXXXXX,
    XXXXXXX, KC_AT,   KC_LPRN, KC_RPRN, KC_UNDS, KC_PIPE, KC_DLR,  KC_LEFT, KC_DOWN, KC_RGHT, KC_TILD, XXXXXXX,
    _______, KC_EXLM, KC_LCBR, KC_RCBR, KC_QUES, KC_HASH, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS, _______,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

/* Raise
  * ,-----------------------------------------------. ,-----------------------------------------------.
  * |       |       |       |       |       |       | |   *   |   7   |   8   |   9   |   =   |  Del  |
  * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
  * |       |       |       |       |       |       | |   +   |   4   |   5   |   6   |   -   |       |
  * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
  * |       |       |       |       |       |       | |   0   |   1   |   2   |   3   |   /   |       |
  * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
  * |       |       |       |       |       |       | |       |[Raise]|       |       |       |       |
  * `-----------------------------------------------' `-----------------------------------------------'
  */
  [_RAISE] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ASTR, KC_7,    KC_8,    KC_9,    KC_EQL,  KC_DEL,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PLUS, KC_4,    KC_5,    KC_6,    KC_MINS, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_0,    KC_1,    KC_2,    KC_3,    KC_SLSH, _______,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

/* Func
  * ,-----------------------------------------------. ,-----------------------------------------------.
  * |       | Mode+ | Hue+  | Satu+ | Brit+ |       | |  F12  |   F7  |   F8  |   F9  |       |Ct+Al+D|
  * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
  * |       | Mode- | Hue-  | Satu- | Brit- |       | |  F11  |   F4  |   F5  |   F6  |       |       |
  * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
  * |       |       |       |       |       |       | |  F10  |   F1  |   F2  |   F3  |       |       |
  * |-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------|
  * |       |       |       |       |       |       | |       |       |       |       |       |       |
  * `-----------------------------------------------' `-----------------------------------------------'
  */
  [_FUNC] = LAYOUT(
    XXXXXXX, RM_NEXT, RM_HUEU, RM_SPDU, RM_VALU, XXXXXXX, KC_F12,  KC_F7,   KC_F8,   KC_F9,   XXXXXXX, CTLALTD,
    XXXXXXX, RM_PREV, RM_HUED, RM_SPDD, RM_VALD, XXXXXXX, KC_F11,  KC_F4,   KC_F5,   KC_F6,   XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F10,  KC_F1,   KC_F2,   KC_F3,   XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),
};

// 各レイヤーのキーごとの色　偶数業は右から左なので注意
uint8_t lowerLeds[] = { 0, 1, 1, 1, 1, 1,
                        1, 1, 1, 1, 1, 0,
                        0, 1, 1, 1, 1, 1,
                        0, 0, 0, 0, 0, 0,

                        0, 0, 2, 0, 1, 0,
                        0, 1, 2, 2, 2, 1,
                        0, 0, 0, 0, 1, 0,
                        0, 0, 0, 0, 0, 0
                      };
uint8_t raiseLeds[] = { 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0,

                        1, 2, 2, 2, 1, 3,
                        0, 1, 2, 2, 2, 1,
                        2, 2, 2, 2, 1, 0,
                        0, 0, 0, 0, 0, 0
                      };
uint8_t funcLeds[]  = { 0, 5, 5, 5, 5, 0,
                        0, 5, 5, 5, 5, 0,
                        0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0,

                        4, 4, 4, 4, 0, 5,
                        0, 0, 4, 4, 4, 4,
                        4, 4, 4, 4, 0, 0,
                        0, 0, 0, 0, 0, 0
                      };

// レイヤーごとにLED色をかえる
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

  switch(get_highest_layer(layer_state|default_layer_state)) {
      case 1:
          for (uint8_t i = 0; i < 48; i++) {
            if (lowerLeds[i] == 0) rgb_matrix_set_color(i, 0, 0, 0);// 黒
            if (lowerLeds[i] == 1) rgb_matrix_set_color(i, 0, 48, 8);// シアン 記号
            if (lowerLeds[i] == 2) rgb_matrix_set_color(i, 128, 24, 0);// オレンジ カーソル
          }
          break;
      case 2:
          for (uint8_t i = 0; i < 48; i++) {
            if (raiseLeds[i] == 0) rgb_matrix_set_color(i, 0, 0, 0);// 黒
            if (raiseLeds[i] == 1) rgb_matrix_set_color(i, 0, 48, 8);// シアン 記号
            if (raiseLeds[i] == 2) rgb_matrix_set_color(i, 0, 0, 48);// 青 数字
            if (raiseLeds[i] == 3) rgb_matrix_set_color(i, 128, 0, 0);// 赤 del
          }
          break;
      case 3:
          for (uint8_t i = 0; i < 48; i++) {
            if (funcLeds[i] == 0) rgb_matrix_set_color(i, 0, 0, 0);// 黒
            if (funcLeds[i] == 4) rgb_matrix_set_color(i, 64, 0, 92);// 紫
            if (funcLeds[i] == 5) rgb_matrix_set_color(i, 128, 16, 16);// ピンク
          }
          break;
      default:
          break;
  }
  return false;
}

