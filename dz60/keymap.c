#include QMK_KEYBOARD_H

#define ______ KC_TRNS

#define RSFT_Q RSFT_T(KC_SLSH)   // right shift on hold, / on tap

enum custom_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY
};

#ifdef TAP_DANCE_ENABLE
qk_tap_dance_action_t tap_dance_actions[] = {
  // tap once for F4, twice for ALT+F4
  [0] = ACTION_TAP_DANCE_DOUBLE(KC_F4, LALT(KC_F4)),
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------------------------------------------------------.
   * | ` ~ |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |   Bkspc   |
   * |-----------------------------------------------------------------------------------------+
   * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \   |
   * |-----------------------------------------------------------------------------------------+
   * | Caps    |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
   * |-----------------------------------------------------------------------------------------+
   * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  | RSh |  U  | DEL |
   * |-----------------------------------------------------------------------------------------+
   * | Ctrl |  Cmd  |  Alt  |              Space                | RAlt | FN  |  L  |  D  |  R  |
   * `-----------------------------------------------------------------------------------------'
   */

  LAYOUT_directional(
      KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, ______, KC_BSPC,
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
      KC_LGUI, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
      KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT_Q, KC_UP, KC_DEL,
      KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_SPC, MO(2), KC_RALT, KC_LEFT, KC_DOWN, KC_RIGHT
    ),

  LAYOUT_directional(
      KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, ______, KC_BSPC,
      KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_T, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS,
      KC_LGUI, KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_K, KC_I, KC_O, KC_QUOT, KC_ENT,
      KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT_Q, KC_UP, KC_DEL,
      KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_SPC, MO(2), KC_RALT, KC_LEFT, KC_DOWN, KC_RIGHT
    ),


  /* FN Layer
   * ,-----------------------------------------------------------------------------------------.
   * | Esc |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |   RESET   |
   * |-----------------------------------------------------------------------------------------+
   * |        |RBB T|RGB M| Hue+| Hue-| Sat+| Sat-| Val+| Val-|     |     |      |      |      |
   * |-----------------------------------------------------------------------------------------+
   * |         | BL T| BL M| BL+ | BL- |     |     |     |     |     |     |     |             |
   * |-----------------------------------------------------------------------------------------+
   * |           |     |     |     |     |     |     |     |     |     |     |     |     |     |
   * |-----------------------------------------------------------------------------------------+
   * |      |       |       |                                   |     |      |     |     |     |
   * `-----------------------------------------------------------------------------------------'
   */

  LAYOUT_directional(
      KC_GRV, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_F11, KC_F12, KC_TRNS, KC_MUTE,
      ______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, ______, ______, ______, QWERTY, COLEMAK,
      ______, BL_TOGG, BL_STEP, BL_INC, BL_DEC, ______, ______, ______, ______, ______, ______, ______,
      ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, KC_VOLU, KC_MPLY,
      ______, ______, ______, RESET, RESET, RESET,  ______, ______, KC_MPRV, KC_VOLU, KC_MNXT
      ),
};


// set a persistant default layer
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case COLEMAK:
        if (record->event.pressed) {
            set_single_persistent_default_layer(0);
        }
        return false;
        break;
    case QWERTY:
        if (record->event.pressed) {
            set_single_persistent_default_layer(1);
        }
        return false;
        break;
    default:
      return true;
  }
  return true;
};
