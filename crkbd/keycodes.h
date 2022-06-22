// Copyright 2022 Álvaro Cortés (@ACortesDev)
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

#include QMK_KEYBOARD_H
#include "layers.h"

/* Tap-Hold keycodes */
/* #define KC_LOWER LT(_LOWER, KC_ENT) /1* Tap for Enter, Hold for LOWER layer *1/ */
/* #define KC_RAISE LT(_RAISE, KC_SPC) /1* Tap for Space, Hold for RAISE layer *1/ */

/* one shot layer */
#define KC_LOWER OSL(_LOWER) /* Tap for Enter, Hold for LOWER layer */
#define KC_RAISE OSL(_RAISE) /* Tap for Space, Hold for RAISE layer */

/* Tap Dance keycodes */
#if defined(TAP_DANCE_ENABLE)
    #include "tap_dances.h"
    /* #define KC_T_SFT T_SFT /1* Single tap for Shift, Double tap for CAPS Lock *1/ */
    #define KC_T_F4 T_F4
#else
    /* #define KC_T_SFT KC_LSFT */
    #define KC_T_F4 KC_F4
#endif

/* Macros */
enum custom_keycodes {
    VSCTERM = SAFE_RANGE,
    CHNLANG 
};

#define KC_CTLEC CTL_T(KC_ESC)
