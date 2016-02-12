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
#include "action_layer.h"
#include "keymap_common.h"

#define KC_STAR KC_NONUS_HASH
#define KC_SQR KC_GRAVE
#define KC_LTGT KC_NONUS_BSLASH
#define KC_EXEC KC_EXECUTE
#define KC_BLDN KC_FN3
#define KC_BLUP KC_FN4
#define KC_SCRS KC_FN5
#define KC_VMEN KC_FN6
#define KC_VCHU KC_FN7
#define KC_VCHD KC_FN8
#define KC_VVLU KC_FN9
#define KC_VVLD KC_FN10
#define KC_VPWR KC_FN11

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
     * |   |   |   |   |   |                |   |   |   |VMn|~~~~~|VCu|~~~~|
     * |-------------------------------------------------------------------|
     * |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|VVd|VCd|VVup|
     * `-------------------------------------------------------------------'
     * Src: Press video converter input key
     * LDn:  backlight down one level
     * LUp: backlight up one level
     * NmL: to numlock overlay (and activate num lock status)
     * VMn: Press video converter menu key
     * VCu: Press video converter channel up key
     * VCd: Press video converter channel down key
     * VVu: Press video converter volume up key
     * VVd: Press video converter volume down key
     */
    KEYMAP(
                                   TRNS,TRNS,TRNS,   TRNS,TRNS,TRNS,                         \
        TRNS,EXEC,HELP,SCRS,SLEP,TRNS,TRNS,BLDN,BLUP,MPLY,MSTP,MPRV,MNXT,TRNS,FN1,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS, TRNS,TRNS, TRNS, TRNS,TRNS, TRNS,TRNS, TRNS,TRNS,    TRNS,TRNS, \
        TRNS, TRNS,TRNS,TRNS, TRNS,TRNS, TRNS, TRNS,TRNS, TRNS,TRNS, TRNS,TRNS,   TRNS,TRNS, \
        TRNS,  TRNS,TRNS,TRNS, TRNS, TRNS,TRNS, TRNS,TRNS, TRNS, TRNS,TRNS,       TRNS,TRNS, \
        TRNS,   TRNS,TRNS,TRNS, TRNS, TRNS, TRNS,TRNS, TRNS, TRNS, TRNS,          TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,        TRNS,TRNS,TRNS,VMEN,          VCHU,       \
                                                                            VVLU,VCHD,VVLD   ),                                                                          
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
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN2,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS, TRNS,TRNS, TRNS,   P7,  P8,   P9,PAST, TRNS,TRNS,    TRNS,TRNS, \
        TRNS, TRNS,TRNS,TRNS, TRNS,TRNS, TRNS,   P4,  P5,   P6,PMNS, TRNS,TRNS,   TRNS,TRNS, \
        TRNS,  TRNS,TRNS,TRNS, TRNS, TRNS,TRNS,   P1,  P2,   P3, PPLS,TRNS,       TRNS,TRNS, \
        TRNS,   TRNS,TRNS,TRNS, TRNS, TRNS, TRNS,  P0, TRNS, PDOT, PSLS,          TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,        TRNS,TRNS,TRNS,TRNS,          TRNS,       \
                                                                            TRNS,TRNS,TRNS   ),                                                                          
};

enum function_id {
    VIDEO_MENU,
    VIDEO_CH_UP,
    VIDEO_CH_DOWN,
    VIDEO_VOL_UP,
    VIDEO_VOL_DOWN,
    VIDEO_INPUT,
    VIDEO_POWER,
    NUM_LOCK_ON,
    NUM_LOCK_OFF,
};

#define VIDEO_MIN VIDEO_MENU
#define VIDEO_MAX VIDEO_POWER
#define VIDEO_MASK 0x07

const uint16_t PROGMEM fn_actions[] = {
    /* Presario 2710 Layout */
    [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
    [1] = ACTION_FUNCTION(NUM_LOCK_ON),  // function to press NumLock key then activate layer 2
    [2] = ACTION_FUNCTION(NUM_LOCK_OFF), // function to deactivate layer 2 then press NumLock key 
    [3] = ACTION_BACKLIGHT_DECREASE(),
    [4] = ACTION_BACKLIGHT_INCREASE(),
    [5] = ACTION_FUNCTION(VIDEO_INPUT),
    [6] = ACTION_FUNCTION(VIDEO_MENU),
    [7] = ACTION_FUNCTION(VIDEO_CH_UP),
    [8] = ACTION_FUNCTION(VIDEO_CH_DOWN),
    [9] = ACTION_FUNCTION(VIDEO_VOL_UP),
    [10] = ACTION_FUNCTION(VIDEO_VOL_DOWN),
    [11] = ACTION_FUNCTION(VIDEO_POWER),
};

/*
 * user defined action function
 */
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    if (record->event.pressed) dprint("P"); else dprint("R");
    dprintf("%d", record->tap.count);
    if (record->tap.interrupted) dprint("i");
    dprint("\n");
    
    if (id >= VIDEO_MIN && id <= VIDEO_MAX)
    {
        PORTA &= ~VIDEO_MASK;
        if (record->event.pressed)
            PORTA |= id & VIDEO_MASK;
    }
    else
    {
      switch (id) {
          case NUM_LOCK_ON:
              if (record->event.pressed)
              {
                  register_code(KC_NUMLOCK);
                  unregister_code(KC_NUMLOCK);
                  layer_on(2);
              }
              break;
          case NUM_LOCK_OFF:
              if (record->event.pressed)
              {
                  layer_off(2);
                  register_code(KC_NUMLOCK);
                  unregister_code(KC_NUMLOCK);
              }
              break;
      }
    }
}
