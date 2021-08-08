/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
	_COLEMAK,
	_LOWER,
	_RAISE,
};

enum planck_keycodes {
	COLEMAK = SAFE_RANGE,
	// Encoder Mods
	ENC_ALT,
	ENC_GUI,
	ENC_CTRL,
	G_SWAP,
	EEQL,
	NEQL,
	LEQL,
	GEQL,
	C_OR,
	C_AND,
	PP,
	MM,
	PE,
	ME,
};

#define MEDIA_KEY_DELAY 10

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FN1 MO(_FN1)
#define FN2 LT(_FN2, KC_LEFT)

// Modifier Tap
#define ESC_TAP LGUI_T(KC_ESC)

// One Shot Layers and Mods
#define OSL_LWR OSL(_LOWER)
#define OSL_RAS OSL(_RAISE)
#define OSM_LST OSM(MOD_LSFT)
#define OSM_RST OSM(MOD_RSFT)

// Tap Dance define
#ifdef TAP_DANCE_ENABLE
#define EXT_APP TD(0)
#endif

#ifdef TAP_DANCE_ENABLE
qk_tap_dance_action_t tap_dance_actions[] = {
	// tap once for F4, twice for ALT+F4
	[0] = ACTION_TAP_DANCE_DOUBLE(KC_F4, LALT(KC_F4)),
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_COLEMAK] = LAYOUT_planck_grid(
			KC_MPLY,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_TAB,
			ESC_TAP,   KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT,
			OSM_LST,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, OSM_RST,
			ENC_CTRL,  KC_LGUI,  ENC_GUI, ENC_ALT, OSL_LWR, KC_SPC,  KC_BSPC, OSL_RAS, KC_RGUI, KC_RALT, KC_RALT, KC_RCTRL
	),

	[_RAISE] = LAYOUT_planck_grid(
			_______, C_OR,     C_AND,   ME,      PE,      PP,       KC_CIRC, KC_AMPR,  KC_ASTR,   KC_LPRN,  KC_RPRN, KC_GRV,
			_______, LEQL,     EEQL,    NEQL,    GEQL,    KC_TILDE, KC_LEFT, KC_DOWN,  KC_UP,     KC_RIGHT, KC_PIPE, KC_DQT,
			KC_LBRC, _______,  _______, _______, _______, MM,       KC_HOME, KC_PGDN,  KC_PGUP,   KC_END,   KC_BSLS, KC_RBRC,
			_______, _______,  _______, _______, _______, _______,  _______, _______,  KC_MPRV,  KC_VOLD,  KC_VOLU, KC_MNXT
	),

	[_LOWER] = LAYOUT_planck_grid(
			_______,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_PLUS, KC_F1,   KC_F2,   KC_F3,    EXT_APP, KC_UNDS,
			_______,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_EQL,  KC_F5,   KC_F6,   KC_F7,    KC_F8,   KC_QUOT,
			KC_LCBR,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_RCBR,
			_______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______
	),

};

// flags for encoder and alt gui swap
bool lalt = false, lctrl = false, lgui = false, ag_swap = true;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case COLEMAK:
			if (record->event.pressed) {
				set_single_persistent_default_layer(_COLEMAK);
			}
			return false;
			break;
		case G_SWAP:
			if (record->event.pressed) {
				ag_swap = !ag_swap;
			}
			return false;
			break;

		case ENC_ALT:
			if (record->event.pressed) {
				(ag_swap) ? register_code(KC_LALT) : register_code(KC_LGUI);
				lalt = !lalt;
			} else {
				(ag_swap) ? unregister_code(KC_LALT) : unregister_code(KC_LGUI);
				lalt = !lalt;
			}
			return false;
			break;

		case ENC_GUI:
			if (record->event.pressed) {
				(ag_swap) ? register_code(KC_LGUI) : register_code(KC_LALT);
				lgui = !lgui;
			} else {
				(ag_swap) ? unregister_code(KC_LGUI) : unregister_code(KC_LALT);
				lgui = !lgui;
			}
			return false;
			break;

		case ENC_CTRL:
			if (record->event.pressed) {
				register_code(KC_LCTRL);
				lctrl = !lctrl;
			} else {
				unregister_code(KC_LCTRL);
				lctrl = !lctrl;
			}
			return false;
			break;
		case EEQL:
			if (record->event.pressed) {
				SEND_STRING("==");
			}
			break;
		case NEQL:
			if (record->event.pressed) {
				SEND_STRING("!=");
			}
			break;
		case LEQL:
			if (record->event.pressed) {
				SEND_STRING("<=");
			}
			break;
		case GEQL:
			if (record->event.pressed) {
				SEND_STRING(">=");
			}
			break;
		case C_OR:
			if ( record->event.pressed ) {
				SEND_STRING("||");
			}
			break;
		case C_AND:
			if ( record->event.pressed ) {
				SEND_STRING("&&");
			}
			break;
		case PP:
			if ( record->event.pressed ) {
				SEND_STRING("++");
			}
			break;
		case MM:
			if ( record->event.pressed ) {
				SEND_STRING("--");
			}
			break;
		case PE:
			if ( record->event.pressed ) {
				SEND_STRING("+=");
			}
			break;
		case ME:
			if ( record->event.pressed ) {
				SEND_STRING("-=");
			}
			break;
	}
	return true;
}


void encoder_update( bool clockwise) {
	uint16_t held_keycode_timer = timer_read();
	if (IS_LAYER_ON(_LOWER)) {
		if (!clockwise) {
			register_code(KC_VOLU);
			while (timer_elapsed(held_keycode_timer) < MEDIA_KEY_DELAY) {
				continue;
			}
			unregister_code(KC_VOLU);
		} else {
			register_code(KC_VOLD);
			while (timer_elapsed(held_keycode_timer) < MEDIA_KEY_DELAY) {
				continue;
			}
			unregister_code(KC_VOLD);
		}
	} else if (lalt || lctrl) {
		if (!clockwise) tap_code(KC_TAB);
		else {
			register_code(KC_LSFT);
			tap_code(KC_TAB);
			unregister_code(KC_LSFT);
		}
	} else if (IS_LAYER_ON(_RAISE)) {
		(!clockwise) ? tap_code(KC_RIGHT) :tap_code(KC_LEFT);
	} else {
		if (!clockwise) {
#ifdef MOUSEKEY_ENABLE
			register_code(KC_MS_WH_DOWN);
			unregister_code(KC_MS_WH_DOWN);
#else
			register_code(KC_PGDN);
			unregister_code(KC_PGDN);
#endif
		} else {
#ifdef MOUSEKEY_ENABLE
			register_code(KC_MS_WH_UP);
			unregister_code(KC_MS_WH_UP);
#else
			register_code(KC_PGUP);
			unregister_code(KC_PGUP);
#endif
		}
	}
}
