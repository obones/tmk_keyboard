/*
Copyright 2016 Olivier Sannier <obones@gmail.com>

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
#ifndef KEYMAP_COMMON_H
#define KEYMAP_COMMON_H

#include <stdint.h>
#include <stdbool.h>
#include <avr/pgmspace.h>
#include "keycode.h"
#include "action.h"
#include "action_macro.h"
#include "report.h"
#include "host.h"
#include "print.h"
#include "debug.h"
#include "keymap.h"


extern const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS];
extern const uint16_t fn_actions[];


/* Presario 2710 keymap definition macro
 */
#define KEYMAP( \
                               K0C, K1C, K2C,    K3C, K4C, K5C,                          \
    K23, K13, K03, K02, K12, K29, K19, K09, K0A, K1A, K27, K17, K1D, K0E, K1E, K1F, K2F, \
    K20, K30, K33, K32,  K35, K25,  K26,  K36, K39,  K37, K2D,  K0D, K2E,      K3E, K3F, \
    K10,  K40, K43, K42,  K45, K15,  K16,  K46, K49,  K47, K3D,  K4D, K4E,     K5E, K4F, \
    K22,    K50, K53,  K52, K55,  K05,  K06, K56, K59,  K57, K5D, K6E,         K7E, K5F, \
    K78,      K73, K63, K62, K65,  K75,  K76,  K66, K69,  K67, K6D,            K68, K6F, \
    K00, K7B, K74, K71, K3A,       K72,         K79, K61, K6C, K4A,           K7D,       \
                                                                         K5A, K77, K7F   \
) { \
    { KC_##K00, KC_NO,    KC_##K02, KC_##K13, KC_NO,    KC_##K05, KC_##K06, KC_NO,    KC_NO,    KC_##K09, KC_##K0A, KC_NO,    KC_##K0C, KC_##K0D, KC_##K0E, KC_NO    }, \
    { KC_##K10, KC_NO,    KC_##K12, KC_##K13, KC_NO,    KC_##K15, KC_##K16, KC_##K17, KC_NO,    KC_##K19, KC_##K1A, KC_NO,    KC_##K1C, KC_##K1D, KC_##K1E, KC_##K1F }, \
    { KC_##K20, KC_NO,    KC_##K22, KC_##K23, KC_NO,    KC_##K25, KC_##K26, KC_##K27, KC_NO,    KC_##K29, KC_NO,    KC_NO,    KC_##K2C, KC_##K2D, KC_##K2E, KC_##K2F }, \
    { KC_##K30, KC_NO,    KC_##K32, KC_##K33, KC_NO,    KC_##K35, KC_##K36, KC_##K37, KC_NO,    KC_##K39, KC_##K3A, KC_NO,    KC_##K3C, KC_##K3D, KC_##K3E, KC_##K3F }, \
    { KC_##K40, KC_NO,    KC_##K42, KC_##K43, KC_NO,    KC_##K45, KC_##K46, KC_##K47, KC_NO,    KC_##K49, KC_##K4A, KC_NO,    KC_##K4C, KC_##K4D, KC_##K4E, KC_##K4F }, \
    { KC_##K50, KC_NO,    KC_##K52, KC_##K53, KC_NO,    KC_##K55, KC_##K56, KC_##K57, KC_NO,    KC_##K59, KC_##K5A, KC_NO,    KC_##K5C, KC_##K5D, KC_##K5E, KC_##K5F }, \
    { KC_NO,    KC_##K61, KC_##K62, KC_##K63, KC_NO,    KC_##K65, KC_##K66, KC_##K67, KC_##K68, KC_##K69, KC_NO,    KC_NO,    KC_##K6C, KC_##K6D, KC_##K6E, KC_##F6F }, \
    { KC_NO,    KC_##K71, KC_##K72, KC_##K73, KC_##K74, KC_##K75, KC_##K76, KC_##K77, KC_##K78, KC_##K79, KC_NO,    KC_##K7B, KC_NO,    KC_##K7D, KC_##K7E, KC_##K7F }, \
}

#endif
