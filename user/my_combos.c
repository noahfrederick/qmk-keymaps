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

#include "my.h"

enum combo_events {
  MY_COMBO_AB,
  MY_COMBO_AN,
  MY_COMBO_AT,
  MY_COMBO_AW,
  MY_COMBO_BC,
  MY_COMBO_CW,
  MY_COMBO_DL,
  MY_COMBO_EG,
  MY_COMBO_EI,
  MY_COMBO_HT,
  MY_COMBO_HV,
  MY_COMBO_IO,
  MY_COMBO_IT,
  MY_COMBO_IW,
  MY_COMBO_KM,
  MY_COMBO_LT,
  MY_COMBO_LW,
  MY_COMBO_MT,
  MY_COMBO_RU,
  MY_COMBO_RY,
  MY_COMBO_UY,
};

const uint16_t PROGMEM combo_ab[] = { KC_A, KC_B, COMBO_END };
const uint16_t PROGMEM combo_an[] = { KC_A, KC_N, COMBO_END };
const uint16_t PROGMEM combo_at[] = { KC_A, KC_T, COMBO_END };
const uint16_t PROGMEM combo_aw[] = { KC_A, KC_W, COMBO_END };
const uint16_t PROGMEM combo_bc[] = { KC_B, KC_C, COMBO_END };
const uint16_t PROGMEM combo_cw[] = { KC_C, KC_W, COMBO_END };
const uint16_t PROGMEM combo_dl[] = { KC_D, KC_L, COMBO_END };
const uint16_t PROGMEM combo_eg[] = { KC_E, KC_G, COMBO_END };
const uint16_t PROGMEM combo_ei[] = { KC_E, KC_I, COMBO_END };
const uint16_t PROGMEM combo_ht[] = { KC_H, KC_T, COMBO_END };
const uint16_t PROGMEM combo_hv[] = { KC_H, KC_V, COMBO_END };
const uint16_t PROGMEM combo_io[] = { KC_I, KC_O, COMBO_END };
const uint16_t PROGMEM combo_it[] = { KC_I, KC_T, COMBO_END };
const uint16_t PROGMEM combo_iw[] = { KC_I, KC_W, COMBO_END };
const uint16_t PROGMEM combo_km[] = { KC_K, KC_M, COMBO_END };
const uint16_t PROGMEM combo_lt[] = { KC_L, KC_T, COMBO_END };
const uint16_t PROGMEM combo_lw[] = { KC_L, KC_W, COMBO_END };
const uint16_t PROGMEM combo_mt[] = { KC_M, KC_T, COMBO_END };
const uint16_t PROGMEM combo_ru[] = { KC_R, KC_U, COMBO_END };
const uint16_t PROGMEM combo_ry[] = { KC_R, KC_Y, COMBO_END };
const uint16_t PROGMEM combo_uy[] = { KC_U, KC_Y, COMBO_END };

const uint16_t PROGMEM combo_zx[] = { KC_Z, KC_X, COMBO_END };
const uint16_t PROGMEM combo_xc[] = { KC_X, KC_C, COMBO_END };
const uint16_t PROGMEM combo_cv[] = { KC_C, KC_V, COMBO_END };
const uint16_t PROGMEM combo_zv[] = { KC_Z, KC_V, COMBO_END };

combo_t key_combos[COMBO_COUNT] = {
  [MY_COMBO_AB] = COMBO_ACTION(combo_ab),
  [MY_COMBO_AN] = COMBO_ACTION(combo_an),
  [MY_COMBO_AT] = COMBO_ACTION(combo_at),
  [MY_COMBO_AW] = COMBO_ACTION(combo_aw),
  [MY_COMBO_BC] = COMBO_ACTION(combo_bc),
  [MY_COMBO_CW] = COMBO_ACTION(combo_cw),
  [MY_COMBO_DL] = COMBO_ACTION(combo_dl),
  [MY_COMBO_EG] = COMBO_ACTION(combo_eg),
  [MY_COMBO_EI] = COMBO_ACTION(combo_ei),
  [MY_COMBO_HT] = COMBO_ACTION(combo_ht),
  [MY_COMBO_HV] = COMBO_ACTION(combo_hv),
  [MY_COMBO_IO] = COMBO_ACTION(combo_io),
  [MY_COMBO_IT] = COMBO_ACTION(combo_it),
  [MY_COMBO_IW] = COMBO_ACTION(combo_iw),
  [MY_COMBO_KM] = COMBO_ACTION(combo_km),
  [MY_COMBO_LT] = COMBO_ACTION(combo_lt),
  [MY_COMBO_LW] = COMBO_ACTION(combo_lw),
  [MY_COMBO_MT] = COMBO_ACTION(combo_mt),
  [MY_COMBO_RU] = COMBO_ACTION(combo_ru),
  [MY_COMBO_RY] = COMBO_ACTION(combo_ry),
  [MY_COMBO_UY] = COMBO_ACTION(combo_uy),
  COMBO(combo_zx, KC_CUT),
  COMBO(combo_xc, KC_COPY),
  COMBO(combo_cv, KC_PASTE),
  COMBO(combo_zv, KC_UNDO),
};

void process_combo_event(uint8_t combo_index, bool pressed) {
  switch(combo_index) {
    case MY_COMBO_AB:
      if (pressed) {
        SEND_STRING("about ");
      }
      break;
    case MY_COMBO_AN:
      if (pressed) {
        SEND_STRING("and ");
      }
      break;
    case MY_COMBO_AT:
      if (pressed) {
        SEND_STRING("@");
      }
      break;
    case MY_COMBO_AW:
      if (pressed) {
        SEND_STRING("what ");
      }
      break;
    case MY_COMBO_BC:
      if (pressed) {
        SEND_STRING("because ");
      }
      break;
    case MY_COMBO_CW:
      if (pressed) {
        SEND_STRING("which ");
      }
      break;
    case MY_COMBO_DL:
      if (pressed) {
        SEND_STRING("would ");
      }
      break;
    case MY_COMBO_EG:
      if (pressed) {
        SEND_STRING("e.g., ");
      }
      break;
    case MY_COMBO_EI:
      if (pressed) {
        SEND_STRING("i.e., ");
      }
      break;
    case MY_COMBO_HT:
      if (pressed) {
        SEND_STRING("the ");
      }
      break;
    case MY_COMBO_HV:
      if (pressed) {
        SEND_STRING("have ");
      }
      break;
    case MY_COMBO_IO:
      if (pressed) {
        SEND_STRING("tion "); // Suffix
      }
      break;
    case MY_COMBO_IT:
      if (pressed) {
        SEND_STRING("this ");
      }
      break;
    case MY_COMBO_IW:
      if (pressed) {
        SEND_STRING("with ");
      }
      break;
    case MY_COMBO_KM:
      if (pressed) {
        SEND_STRING("make ");
      }
      break;
    case MY_COMBO_LT:
      if (pressed) {
        SEND_STRING("until ");
      }
      break;
    case MY_COMBO_LW:
      if (pressed) {
        SEND_STRING("will ");
      }
      break;
    case MY_COMBO_MT:
      if (pressed) {
        SEND_STRING("ment "); // Suffix
      }
      break;
    case MY_COMBO_RU:
      if (pressed) {
        SEND_STRING("you're ");
      }
      break;
    case MY_COMBO_RY:
      if (pressed) {
        SEND_STRING("your ");
      }
      break;
    case MY_COMBO_UY:
      if (pressed) {
        SEND_STRING("you ");
      }
      break;
  }
}
