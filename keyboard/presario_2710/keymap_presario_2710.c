#include "keymap_common.h"

#define KC_STAR KC_NONUS_HASH
#define KC_SQR KC_GRAVE
#define KC_LTGT KC_NONUS_BSLASH
#define KC_EXEC KC_EXECUTE
#define KC_SCRS KC_TRNS
#define KC_BLDN KC_TRNS
#define KC_BLUP KC_TRNS

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: default, French azerty. Note that qwerty is used here because of USB recommandations */
    KEYMAP(
        ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,PSCR,SLCK,PAUS, DEL, \
        SQR, 1,   2,   3,    4,   5,    6,    7,   8,    9,   0,    MINS,EQL,     BSPC,HOME, \
        TAB,  Q,   W,   E,    R,   T,    Y,    U,   I,    O,   P,   LBRC,RBRC,    STAR,PGUP, \
        CAPS,   A,   S,    D,   F,    G,    H,   J,   K,    L,  SCLN,QUOT,         ENT,PGDN, \
        LSFT,     Z,   X,   C,   V,    B,    N,    M,  COMM,  DOT, SLSH,          RSFT, END, \
        FN0,LCTL,LGUI,LALT,LTGT,       SPC,         INS,RALT,RGUI, APP,           UP,        \
                                                                            LEFT,DOWN,RGHT   ),                                                                          
    /* 1: Fn
     * ,-------------------------------------------------------------------.
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
        TRNS,EXEC,HELP,SCRS,SLEP,TRNS,TRNS,BLDN,BLUP,MPLY,MSTP,MPRV,MNXT,TRNS,FN1,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS, TRNS,TRNS, TRNS, TRNS,TRNS, TRNS,TRNS, TRNS,TRNS,    TRNS,TRNS, \
        TRNS, TRNS,TRNS,TRNS, TRNS,TRNS, TRNS, TRNS,TRNS, TRNS,TRNS, TRNS,TRNS,   TRNS,TRNS, \
        TRNS,  TRNS,TRNS,TRNS, TRNS, TRNS,TRNS, TRNS,TRNS, TRNS, TRNS,TRNS,       TRNS,TRNS, \
        TRNS,   TRNS,TRNS,TRNS, TRNS, TRNS, TRNS,TRNS, TRNS, TRNS, TRNS,          TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,        TRNS,TRNS,TRNS,TRNS,          TRNS,       \
                                                                            TRNS,TRNS,TRNS   ),                                                                          
    /* 2: Numlock
     * ,-------------------------------------------------------------------.
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
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN1,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS, TRNS,TRNS, TRNS,   P7,  P8,   P9,PAST, TRNS,TRNS,    TRNS,TRNS, \
        TRNS, TRNS,TRNS,TRNS, TRNS,TRNS, TRNS,   P4,  P5,   P6,PMNS, TRNS,TRNS,   TRNS,TRNS, \
        TRNS,  TRNS,TRNS,TRNS, TRNS, TRNS,TRNS,   P1,  P2,   P3, PPLS,TRNS,       TRNS,TRNS, \
        TRNS,   TRNS,TRNS,TRNS, TRNS, TRNS, TRNS,  P0, TRNS, PDOT, PSLS,          TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,        TRNS,TRNS,TRNS,TRNS,          TRNS,       \
                                                                            TRNS,TRNS,TRNS   ),                                                                          
};
const uint16_t PROGMEM fn_actions[] = {
    /* Presario 2710 Layout */
    [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
    [1] = ACTION_LAYER_TOGGLE(2),     // to Numlock overlay
};
