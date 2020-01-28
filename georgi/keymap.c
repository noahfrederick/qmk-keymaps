/* Copyright 2019 Jeremy Bernhardt, Noah Frederick
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
#include "sten.h"
#include "my.h"
#define IGNORE_MOD_TAP_INTERRUPT

// Steno Layers
#define FUNCT   ( LSD | LK | LP | LH )
#define MEDIA   ( LSD | LK | LW | LR )
#define MOVE    ( LSD | LK )
#define NUM     ( PWR )
#define SYM     ( RZ )

// Keys and chords that, once they appear, are added to every subsequent partial chord
// until the whole thing is sent.
uint32_t stenoLayers[] = {NUM, SYM, MOVE, MEDIA, FUNCT};

enum keymap_layers {
  GEORGI_BASE_LAYER,
  GAMING_1_LAYER,
  GAMING_2_LAYER
};

/* Keyboard Layout
 * ,-----------------------------------.    ,-----------------------------------.
 * | FN  | LSU | LFT | LP  | LH  | ST1 |    | ST3 | RF  | RP  | RL  | RT  | RD  |
 * |-----+-----+-----+-----+-----|-----|    |-----|-----+-----+-----+-----+-----|
 * | PWR | LSD | LK  | LW  | LR  | ST2 |    | ST4 | RR  | RB  | RG  | RS  | RZ  |
 * `-----------------------------------'    `-----------------------------------'
 *                   ,-----------------,    .-----------------.
 *                   | LNO | LA  | LO  |    | RE  | RU  | RNO |
 *                   `-----------------'    `-----------------'
 */

// Note: You can only use basic keycodes here!
//
// P() is just a wrapper to make your life easier.
// PC() applies the mapping to all of the StenoLayers. For overloading, define these last.
//
// FN is unavailable. That is reserved for system use.
// Chords containing PWR are always available, even in steno mode.
//
// http://docs.gboards.ca
uint32_t processQwerty(bool lookup) {
    // Special keys
    P( RT  | RS  | RD  | RZ | LNO,      SEND_STRING(MY_VERSION));
    P( LFT | LK  | LP  | LW,            REPEAT());

/* Function layer
 * ,-----------------------------------,    ,-----------------------------------,
 * |     |     |     | NCTFUNCTF |     |    |     | F1  | F2  | F3  | F4  |     |
 * |     +     +     +     +     +     |    |     + F5  + F6  + F7  + F8  +     |
 * |     | FUNCTFUNC |     |     |     |    |     | F9  | F10 | F11 | F12 |     |
 * `-----+-----+-----+-----+-----+-----'    `-----+-----+-----+-----+-----+-----'
 */
    P( FUNCT | RF,          SEND(KC_F1));
    P( FUNCT | RP,          SEND(KC_F2));
    P( FUNCT | RL,          SEND(KC_F3));
    P( FUNCT | RT,          SEND(KC_F4));

    P( FUNCT | RF | RR,     SEND(KC_F5));
    P( FUNCT | RP | RB,     SEND(KC_F6));
    P( FUNCT | RL | RG,     SEND(KC_F7));
    P( FUNCT | RT | RS,     SEND(KC_F8));

    P( FUNCT | RR,          SEND(KC_F9));
    P( FUNCT | RG,          SEND(KC_F10));
    P( FUNCT | RB,          SEND(KC_F11));
    P( FUNCT | RS,          SEND(KC_F12));

/* Movement layer
 * ,-----------------------------------,    ,-----------------------------------,
 * |     |     |     |     |     |     |    |     |  ←  |  ↓  |  ↑  |  →  |     |
 * |     +     +     +     +     +     |    |     +     +     +     +     +     |
 * |     | MOVEMOVEM |     |     |     |    |     |Home |PgUp |PgDn | End |     |
 * `-----+-----+-----+-----+-----+-----'    `-----+-----+-----+-----+-----+-----'
 */
    P( MOVE | RF,           SEND(KC_LEFT));
    P( MOVE | RP,           SEND(KC_DOWN));
    P( MOVE | RL,           SEND(KC_UP));
    P( MOVE | RT,           SEND(KC_RIGHT));

    P( MOVE | RR,           SEND(KC_HOME));
    P( MOVE | RB,           SEND(KC_PGDN));
    P( MOVE | RG,           SEND(KC_PGUP));
    P( MOVE | RS,           SEND(KC_END));

/* Media Layer
 * ,-----------------------------------,    ,-----------------------------------,
 * |     |     |     |     |     |     |    |     |Prev |Play |Play |Next | VolU|
 * |     +     +     +     +     +     |    |     +     +     +     +     +     |
 * |     | MEDIAMEDIAMEDIAMEDIAM |     |    |     |     |     |     |Mute | VolD|
 * `-----+-----+-----+-----+-----+-----'    `-----+-----+-----+-----+-----+-----'
 */
    P( MEDIA | RF,          SEND(KC_MPRV));
    P( MEDIA | RP,          SEND(KC_MPLY));
    P( MEDIA | RL,          SEND(KC_MPLY));
    P( MEDIA | RT,          SEND(KC_MNXT));
    P( MEDIA | RD,          SEND(KC_VOLU));

    P( MEDIA | RS,          SEND(KC_MUTE));
    P( MEDIA | RZ,          SEND(KC_VOLD));

/* Numbers
 * ,-----------------------------------,    ,-----------------------------------,
 * |     |     |  a  |  b  |  c  |     |    |  :  |  1  |  2  |  3  |  .  |     |
 * |     +     +  d  +  e  +  f  +     |    |  0  +  4  +  5  +  6  +  -  +     |
 * | NUM |     |     |     |     |     |    |     |  7  |  8  |  9  |  0  |     |
 * `-----+-----+-----+-----+-----+-----'    `-----+-----+-----+-----+-----+-----'
 */
    P( NUM | LFT,           SEND(KC_A));
    P( NUM | LP,            SEND(KC_B));
    P( NUM | LH,            SEND(KC_C));
    P( NUM | LK,            SEND(KC_D));
    P( NUM | LW,            SEND(KC_E));
    P( NUM | LR,            SEND(KC_F));

    // Right hand
    P( NUM | ST3,           SEND_STRING(":"));
    P( NUM | RF,            SEND(KC_1));
    P( NUM | RP,            SEND(KC_2));
    P( NUM | RL,            SEND(KC_3));
    P( NUM | RT,            SEND(KC_DOT));

    P( NUM | ST3 | ST4,     SEND(KC_0));
    P( NUM | RF  | RR,      SEND(KC_4));
    P( NUM | RP  | RB,      SEND(KC_5));
    P( NUM | RG  | RL,      SEND(KC_6));
    P( NUM | RT  | RS,      SEND(KC_MINUS));

    P( NUM | RR,            SEND(KC_7));
    P( NUM | RB,            SEND(KC_8));
    P( NUM | RG,            SEND(KC_9));
    P( NUM | RS,            SEND(KC_0));

/* Symbols
 * ,-----------------------------------,    ,-----------------------------------,
 * |     |  `  |  [  |  {  |  (  |  <  |    |  >  |  )  |  }  |  ]  |  ?  |     |
 * |     +  ~  +  -  +  '  +  :  +  _  |    |  \  +  =  +  "  +  +  +  ?  +     |
 * |     |  !  |  @  |  #  |  $  |  %  |    |  |  |  ^  |  &  |  *  |  ?  | SYM |
 * `-----+-----+-----+-----+-----+-----'    `-----+-----+-----+-----+-----+-----'
 */
    // Left hand
    P( SYM | LSU,           SEND(KC_GRV));
    P( SYM | LFT,           SEND(KC_LBRC));
    P( SYM | LP,            SEND_STRING("{"));
    P( SYM | LH,            SEND_STRING("("));
    P( SYM | ST1,           SEND_STRING("<"));

    P( SYM | LSU | LSD,     SEND_STRING("~"));
    P( SYM | LFT | LK,      SEND(KC_MINS));
    P( SYM | LP  | LW,      SEND(KC_QUOTE));
    P( SYM | LH  | LR,      SEND_STRING(":"));
    P( SYM | ST1 | ST2,     SEND_STRING("_"));

    P( SYM | LSD,           SEND_STRING("!"));
    P( SYM | LK,            SEND_STRING("@"));
    P( SYM | LW,            SEND_STRING("#"));
    P( SYM | LR,            SEND_STRING("$"));
    P( SYM | ST2,           SEND_STRING("%"));

    // Right hand
    P( SYM | ST3,           SEND_STRING(">"));
    P( SYM | RF,            SEND_STRING(")"));
    P( SYM | RP,            SEND_STRING("}"));
    P( SYM | RL,            SEND_STRING("]"));
    P( SYM | RT,            SEND_STRING("?"));

    P( SYM | ST3 | ST4,     SEND(KC_BSLASH));
    P( SYM | RF  | RR,      SEND(KC_EQUAL));
    P( SYM | RP  | RB,      SEND_STRING("\""));
    P( SYM | RG  | RL,      SEND_STRING("+"));
    P( SYM | RT  | RS,      SEND_STRING("?"));

    P( SYM | ST4,           SEND_STRING("|"));
    P( SYM | RR,            SEND_STRING("^"));
    P( SYM | RB,            SEND_STRING("&"));
    P( SYM | RG,            SEND_STRING("*"));
    P( SYM | RS,            SEND_STRING("?"));

/* Letters
 * ,-----------------------------------,    ,-----------------------------------,
 * |Exit |  Q  |  W  |  F  |  P  |  G  |    |  J  |  L  |  U  |  Y  |  ;  |  '  |
 * + Tab +- A -+- R -+- S -+- T -+- D -|    |- H -+- N -+- E -+- I -+- O -+Enter|
 * | Esc |  Z  |  X  |  C  |  V  |  B  |    |  K  |  M  |  ,  |  .  |  /  |Enter|
 * `-----+-----+-----+-----+-----+-----'    `-----+-----+-----+-----+-----+-----'
 *                   ,-----------------,    .-----------------.
 *                   | GUI |Shift|Space|    |Bspc |LCtrl|LAlt |
 *                   `-----------------'    `-----------------'
 */
    // Left hand
    P( PWR,                 SEND(KC_ESC));
    P( PWR | FN,            SEND(KC_TAB));

    P( LSU,                 SEND(KC_Q));
    P( LFT,                 SEND(KC_W));
    P( LP,                  SEND(KC_F));
    P( LH,                  SEND(KC_P));
    P( ST1,                 SEND(KC_G));

    P( LSU | LSD,           SEND(KC_A));
    P( LFT | LK,            SEND(KC_R));
    P( LP  | LW,            SEND(KC_S));
    P( LH  | LR,            SEND(KC_T));
    P( ST1 | ST2,           SEND(KC_D));

    P( LSD,                 SEND(KC_Z));
    P( LK,                  SEND(KC_X));
    P( LW,                  SEND(KC_C));
    P( LR,                  SEND(KC_V));
    P( ST2,                 SEND(KC_B));

    // Right hand
    P( ST3,                 SEND(KC_J));
    P( RF,                  SEND(KC_L));
    P( RP,                  SEND(KC_U));
    P( RL,                  SEND(KC_Y));
    P( RT,                  SEND(KC_SCLN));

    P( ST3 | ST4,           SEND(KC_H));
    P( RF  | RR,            SEND(KC_N));
    P( RP  | RB,            SEND(KC_E));
    P( RG  | RL,            SEND(KC_I));
    P( RT  | RS,            SEND(KC_O));

    P( ST4,                 SEND(KC_K));
    P( RR,                  SEND(KC_M));
    P( RB,                  SEND(KC_COMM));
    P( RG,                  SEND(KC_DOT));
    P( RS,                  SEND(KC_SLSH));

    P( RD,                  SEND(KC_QUOT));
    P( RZ,                  SEND(KC_ENT));
    P( RD | RZ,             SEND(KC_ENT));

    // Thumb Chords and modifiers
    //
    PC( LNO,                SEND(KC_LGUI));
    PC( LA,                 SEND(KC_LSFT));
    PC( LO,                 SEND(KC_SPC));

    PC( RE,                 SEND(KC_BSPC));
    PC( RU,                 SEND(KC_LCTL));
    PC( RNO,                SEND(KC_RALT));

    return 0;
}

// "Layers"
// Steno layer should be first in your map.
// When PWR | FN | ST3 | ST4 is pressed, the layer is increased to the next map.

#define TO_BASE TO(GEORGI_BASE_LAYER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [GEORGI_BASE_LAYER] = LAYOUT_georgi_wrapper(
        STN_FN,  _________________STENO_L2__________________,       _________________STENO_R2___________________________,
        STN_PWR, _________________STENO_L3__________________,       _________________STENO_R3___________________________,
                                   STN_N1,  ____STENO_AO____,       ____STENO_EU____, STN_N7
    ),

    [GAMING_1_LAYER] = LAYOUT_georgi_wrapper(
        KC_TAB,  _________________QWERTY_L1_________________,       _________________QWERTY_R1_________________, KC_QUOT,
        KC_ESC,  _________________QWERTY_L2_________________,       _________________QWERTY_R2_________________, KC_ENT,
                        MO(GAMING_2_LAYER), KC_LSFT, KC_SPC,        KC_BSPC, KC_LCTL, KC_LALT
    ),

    [GAMING_2_LAYER] = LAYOUT_georgi_wrapper(
        _______, _________________NUMBERS_L_________________,       _________________NUMBERS_R_________________, _______,
        TO_BASE, _________________QWERTY_L3_________________,       _________________QWERTY_R3_________________, _______,
                                   _______, _______, _______,       KC_DEL,  _______, _______
    )
};

size_t keymapsCount = sizeof(keymaps) / sizeof(keymaps[0]);
size_t stenoLayerCount = sizeof(stenoLayers) / sizeof(stenoLayers[0]);
