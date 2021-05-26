/*
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

#define KC_CTLEC CTL_T(KC_ESC)
#define KC_LWR OSL(_LOWER)
#define KC_RAS OSL(_RAISE)
#define KC_LST OSM(MOD_LSFT)
#define KC_RST OSM(MOD_RSFT)

// Layer shorthand
enum layer {
    _BASE,
    _LOWER,
		_RAISE
};

// NOTE: maybe make the middle columns media cotorls
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_ortho_hhkb(
        KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_PSCR, KC_MPLY,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
        KC_TAB,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_INS,  KC_DEL,  KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
        KC_CTLEC, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_HOME, KC_PGUP, KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT,
        KC_LST,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_PGDN, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RST,
                  KC_LCTL, KC_LGUI, KC_LALT, KC_LWR,           KC_SPC,  KC_BSPC,          KC_RAS,  KC_RGUI, KC_RALT, KC_RCTL
    ),

    [_LOWER] = LAYOUT_ortho_hhkb(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        KC_CAPS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, KC_PLUS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_UNDS,
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, KC_EQL,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_QUOT,
        _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, _______, KC_MINS, KC_F9,   KC_F10, KC_F11,   KC_F12,  KC_RCBR,
                 _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______
    ),

    [_RAISE] = LAYOUT_ortho_hhkb(
        RESET,   RGB_TOG, RGB_MOD, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, KC_MPLY,
        _______, RGB_HUI, RGB_HUD, _______, _______, _______, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,  KC_RPRN, _______,
        _______, RGB_SAI, RGB_SAD, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_PIPE, KC_DQT,
        _______, RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT,  KC_BSLS, _______,
                 _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______
    )
};
