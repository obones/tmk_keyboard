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
#include "keymap_common.h"

#define KC_STAR KC_NONUS_HASH
#define KC_SQR KC_GRAVE
#define KC_LTGT KC_NONUS_BSLASH
#define KC_EXEC KC_EXECUTE
#define KC_SCRS KC_FN5
#define KC_BLDN KC_FN3
#define KC_BLUP KC_FN4

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: default, French azerty. Note that qwerty is used here because of USB recommandations */
    KEYMAP(
                                   WHOM,MAIL,WSCH,   MSEL,VOLD,VOLU,                         \
        ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,PSCR,SLCK,PAUS, DEL, \
        SQR, 1,   2,   3,    4,   5,    6,    7,   8,    9,   0,    MINS,EQL,     BSPC,HOME, \
        TAB,  Q,   W,   E,    R,   T,    Y,    U,   I,    O,   P,   LBRC,RBRC,    STAR,PGUP, \
        CAPS,   A,   S,    D,   F,    G,    H,   J,   K,    L,  SCLN,QUOT,         ENT,PGDN, \
        LSFT,     Z,   X,   C,   V,    B,    N,    M,  COMM,  DOT, SLSH,          RSFT, END, \
        FN0,LCTL,LGUI,LALT,LTGT,       SPC,         INS,RALT,RGUI, APP,           UP,        \
                                                                            LEFT,DOWN,RGHT   ),                                                                          
    /* 1: Fn
     * ,-------------------------------------------------------------------.
     * |~~~~~~~~~~~~~~~~~~~~~~|  |  |  |~~~~|  |  |  |~~~~~~~~~~~~~~~~~~~~~|
     * |-------------------------------------------------------------------|
     * |   |Exe|Hlp|Src|Slp|   |   |LDn|LUp|Ply|Stp|Prv|Nxt|   |NmL|   |   |
     * |-------------------------------------------------------------------|
     * |   |   |   |   |    |   |   |    |    |   |    |   |   |       |   |
     * |-------------------------------------------------------------------|
     * |     |   |   |   |    |   |   |    |    |   |   |    |   |     |   |
     * |-------------------------------------------------------------------|
     * |       |   |   |   |    |    |   |   |    |   |   |    |       |   |
     * |-------------------------------------------------------------------|
     * |         |   |   |   |    |    |   |   |    |    |   |         |   |
     * |-------------------------------------------------------------------|
     * |   |   |   |   |   |                |   |   |   |   |~~~~~|   |~~~~|
     * |-------------------------------------------------------------------|
     * |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   |   |    |
     * `-------------------------------------------------------------------'
     * Src: Screen input selection (to be implemented)     
     * LDn:  backlight down one level
     * LUp: backlight up one level
     * NmL: to numlock overlay (and activate num lock status)
     */
    KEYMAP(
                                   TRNS,TRNS,TRNS,   TRNS,TRNS,TRNS,                         \
        TRNS,EXEC,HELP,SCRS,SLEP,TRNS,TRNS,BLDN,BLUP,MPLY,MSTP,MPRV,MNXT,TRNS,FN1,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS, TRNS,TRNS, TRNS, TRNS,TRNS, TRNS,TRNS, TRNS,TRNS,    TRNS,TRNS, \
        TRNS, TRNS,TRNS,TRNS, TRNS,TRNS, TRNS, TRNS,TRNS, TRNS,TRNS, TRNS,TRNS,   TRNS,TRNS, \
        TRNS,  TRNS,TRNS,TRNS, TRNS, TRNS,TRNS, TRNS,TRNS, TRNS, TRNS,TRNS,       TRNS,TRNS, \
        TRNS,   TRNS,TRNS,TRNS, TRNS, TRNS, TRNS,TRNS, TRNS, TRNS, TRNS,          TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,        TRNS,TRNS,TRNS,TRNS,          TRNS,       \
                                                                            TRNS,TRNS,TRNS   ),                                                                          
    /* 2: Numlock
     * ,-------------------------------------------------------------------.
     * |~~~~~~~~~~~~~~~~~~~~~~|  |  |  |~~~~|  |  |  |~~~~~~~~~~~~~~~~~~~~~|
     * |-------------------------------------------------------------------|
     * |   |   |   |   |   |   |   |   |   |   |   |   |   |   |NmL|   |   |
     * |-------------------------------------------------------------------|
     * |   |   |   |   |    |   |   |  7 |  8 | 9 |  * |   |   |       |   |
     * |-------------------------------------------------------------------|
     * |     |   |   |   |    |   |   | 4  |  5 | 6 | - |    |   |     |   |
     * |-------------------------------------------------------------------|
     * |       |   |   |   |    |    |   | 1 |  2 | 3 | + |    |       |   |
     * |-------------------------------------------------------------------|
     * |         |   |   |   |    |    |   | 0 |    |  . | / |         |   |
     * |-------------------------------------------------------------------|
     * |   |   |   |   |   |                |   |   |   |   |~~~~~|   |~~~~|
     * |-------------------------------------------------------------------|
     * |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   |   |    |
     * `-------------------------------------------------------------------'
     * NmL: back to default overlay (and deactivate num lock status)
     */
    KEYMAP(
                                   TRNS,TRNS,TRNS,   TRNS,TRNS,TRNS,                         \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN1,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS, TRNS,TRNS, TRNS,   P7,  P8,   P9,PAST, TRNS,TRNS,    TRNS,TRNS, \
        TRNS, TRNS,TRNS,TRNS, TRNS,TRNS, TRNS,   P4,  P5,   P6,PMNS, TRNS,TRNS,   TRNS,TRNS, \
        TRNS,  TRNS,TRNS,TRNS, TRNS, TRNS,TRNS,   P1,  P2,   P3, PPLS,TRNS,       TRNS,TRNS, \
        TRNS,   TRNS,TRNS,TRNS, TRNS, TRNS, TRNS,  P0, TRNS, PDOT, PSLS,          TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,        TRNS,TRNS,TRNS,TRNS,          TRNS,       \
                                                                            TRNS,TRNS,TRNS   ),                                                                          
};

enum macro_id {
    NUM_LOCK,
};

enum function_id {
    SELECT_SOURCE,
};

const uint16_t PROGMEM fn_actions[] = {
    /* Presario 2710 Layout */
    [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
    [1] = ACTION_MACRO(NUM_LOCK),     // macro to press NumLock key then FN2
    [2] = ACTION_LAYER_TOGGLE(2),     // to Numlock overlay
    [3] = ACTION_BACKLIGHT_DECREASE(),
    [4] = ACTION_BACKLIGHT_INCREASE(),
    [5] = ACTION_FUNCTION(SELECT_SOURCE)
};

/*
 * Macro definition
 */
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case NUM_LOCK:
            return (record->event.pressed ?
                    MACRO( I(50), D(NUMLOCK), U(NUMLOCK), D(FN2), END ) :
                    MACRO( U(FN2), END ));
    }
    return MACRO_NONE;
}

/*
 * user defined action function
 */
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    if (record->event.pressed) dprint("P"); else dprint("R");
    dprintf("%d", record->tap.count);
    if (record->tap.interrupted) dprint("i");
    dprint("\n");

    switch (id) {
        case SELECT_SOURCE:
            if (record->event.pressed) {
              // output low 
              DDRA |= _BV(PA0);
              PORTA &= ~_BV(PA0);
            } else {
              // Hi-Z
              DDRA &= ~_BV(PA0);
              PORTA &= ~_BV(PA0);
            }
            break;
    }
}