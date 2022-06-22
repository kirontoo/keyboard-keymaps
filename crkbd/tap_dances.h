// Copyright 2022 Álvaro Cortés (@ACortesDev)
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

#include QMK_KEYBOARD_H

enum custom_tapdances{
    TD_LSFT_CAPS = 0,
    TD_F4
};

#define T_SFT TD(TD_LSFT_CAPS) /* Tap for Shift, double tap for CAPSLOCK */
#define T_F4 TD(TD_F4)
