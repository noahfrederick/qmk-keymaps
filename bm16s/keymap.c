/* Copyright 2019 Noah Frederick
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
#include "my.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Base layer
   *   ┌─────┬─────┬─────┬─────┐
   *   │  7  │  8  │  9  │     │
   *   ├─────┼─────┼─────┼─────┤
   *   │  4  │  5  │  6  │  -  │
   *   ├─────┼─────┼─────┼─────┤
   *   │  1  │  2  │  3  │  +  │
   *   ├─────┼─────┼─────┼─────┤
   *   │  0  │  .  │  ,  │ Ent │
   *   └─────┴─────┴─────┴─────┘
   */
  [0] = LAYOUT_ortho_4x4(
    KC_KP_7, KC_KP_8, KC_KP_9, MO(1),
    KC_KP_4, KC_KP_5, KC_KP_6, KC_PMNS,
    KC_KP_1, KC_KP_2, KC_KP_3, KC_PPLS,
    KC_KP_0, KC_PDOT, KC_PCMM, KC_PENT
  ),

  /* Keyboard settings layer
   *   ┌─────┬─────┬─────┲━━━━━┓
   *   │Reset│Make │Vers ┃     ┃
   *   ├─────┼─────┼─────╄━━━━━┩
   *   │     │     │     │Toggl│
   *   ├─────┼─────┼─────┼─────┤
   *   │Mode-│Hue +│Sat +│Brig+│
   *   ├─────┼─────┼─────┼─────┤
   *   │Mode+│Hue -│Sat -│Brig-│
   *   └─────┴─────┴─────┴─────┘
   */
  [1] = LAYOUT_ortho_4x4(
    RESET,    SEND_MAKE, SEND_VERSION, _______,
    XXXXXXX,  XXXXXXX,   XXXXXXX,      LIT_TOG,
    RGB_RMOD, RGB_HUI,   RGB_SAI,      LIT_INC,
    RGB_MOD,  RGB_HUD,   RGB_SAD,      LIT_DEC
  ),
};
