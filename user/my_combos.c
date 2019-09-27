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
#include "my_leader.h"

enum combo_events {
  MY_COMBO_QUOT_C,
  MY_COMBO_QUOT_D,
  MY_COMBO_QUOT_H,
  MY_COMBO_QUOT_R,
  MY_COMBO_QUOT_S,
  MY_COMBO_QUOT_T,
  MY_COMBO_QUOT_W,
  MY_COMBO_QUOT_Y,
  MY_COMBO_SLSH_F,
  MY_COMBO_SLSH_H,
  MY_COMBO_SLSH_S,
  MY_COMBO_TAB_B,
  MY_COMBO_TAB_C,
  MY_COMBO_TAB_D,
  MY_COMBO_TAB_G,
  MY_COMBO_TAB_I,
  MY_COMBO_TAB_L,
  MY_COMBO_TAB_U,
  MY_COMBO_AB,
  MY_COMBO_AK,
  MY_COMBO_AM,
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
  MY_COMBO_NT,
  MY_COMBO_OW,
  MY_COMBO_RU,
  MY_COMBO_RY,
  MY_COMBO_UY,
};

const uint16_t PROGMEM combo_slsh_f[] = { KC_SLSH, KC_F, COMBO_END };
const uint16_t PROGMEM combo_slsh_h[] = { KC_SLSH, KC_H, COMBO_END };
const uint16_t PROGMEM combo_slsh_s[] = { KC_SLSH, KC_S, COMBO_END };
const uint16_t PROGMEM combo_quot_c[] = { KC_QUOT, KC_C, COMBO_END };
const uint16_t PROGMEM combo_quot_d[] = { KC_QUOT, KC_D, COMBO_END };
const uint16_t PROGMEM combo_quot_h[] = { KC_QUOT, KC_H, COMBO_END };
const uint16_t PROGMEM combo_quot_r[] = { KC_QUOT, KC_R, COMBO_END };
const uint16_t PROGMEM combo_quot_s[] = { KC_QUOT, KC_S, COMBO_END };
const uint16_t PROGMEM combo_quot_t[] = { KC_QUOT, KC_T, COMBO_END };
const uint16_t PROGMEM combo_quot_w[] = { KC_QUOT, KC_W, COMBO_END };
const uint16_t PROGMEM combo_quot_y[] = { KC_QUOT, KC_Y, COMBO_END };
const uint16_t PROGMEM combo_tab_b[] = { KC_TAB, KC_B, COMBO_END };
const uint16_t PROGMEM combo_tab_c[] = { KC_TAB, KC_C, COMBO_END };
const uint16_t PROGMEM combo_tab_d[] = { KC_TAB, KC_D, COMBO_END };
const uint16_t PROGMEM combo_tab_g[] = { KC_TAB, KC_G, COMBO_END };
const uint16_t PROGMEM combo_tab_i[] = { KC_TAB, KC_I, COMBO_END };
const uint16_t PROGMEM combo_tab_l[] = { KC_TAB, KC_L, COMBO_END };
const uint16_t PROGMEM combo_tab_u[] = { KC_TAB, KC_U, COMBO_END };
const uint16_t PROGMEM combo_ab[] = { KC_A, KC_B, COMBO_END };
const uint16_t PROGMEM combo_ak[] = { KC_A, KC_K, COMBO_END };
const uint16_t PROGMEM combo_am[] = { KC_A, KC_M, COMBO_END };
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
const uint16_t PROGMEM combo_nt[] = { KC_N, KC_T, COMBO_END };
const uint16_t PROGMEM combo_ow[] = { KC_O, KC_W, COMBO_END };
const uint16_t PROGMEM combo_ru[] = { KC_R, KC_U, COMBO_END };
const uint16_t PROGMEM combo_ry[] = { KC_R, KC_Y, COMBO_END };
const uint16_t PROGMEM combo_uy[] = { KC_U, KC_Y, COMBO_END };

const uint16_t PROGMEM combo_zx[] = { KC_Z, KC_X, COMBO_END };
const uint16_t PROGMEM combo_xc[] = { KC_X, KC_C, COMBO_END };
const uint16_t PROGMEM combo_cv[] = { KC_C, KC_V, COMBO_END };
const uint16_t PROGMEM combo_zv[] = { KC_Z, KC_V, COMBO_END };

combo_t key_combos[COMBO_COUNT] = {
  [MY_COMBO_QUOT_C] = COMBO_ACTION(combo_quot_c),
  [MY_COMBO_QUOT_D] = COMBO_ACTION(combo_quot_d),
  [MY_COMBO_QUOT_H] = COMBO_ACTION(combo_quot_h),
  [MY_COMBO_QUOT_R] = COMBO_ACTION(combo_quot_r),
  [MY_COMBO_QUOT_S] = COMBO_ACTION(combo_quot_s),
  [MY_COMBO_QUOT_T] = COMBO_ACTION(combo_quot_t),
  [MY_COMBO_QUOT_W] = COMBO_ACTION(combo_quot_w),
  [MY_COMBO_QUOT_Y] = COMBO_ACTION(combo_quot_y),
  [MY_COMBO_SLSH_F] = COMBO_ACTION(combo_slsh_f),
  [MY_COMBO_SLSH_H] = COMBO_ACTION(combo_slsh_h),
  [MY_COMBO_SLSH_S] = COMBO_ACTION(combo_slsh_s),
  [MY_COMBO_TAB_B] = COMBO_ACTION(combo_tab_b),
  [MY_COMBO_TAB_C] = COMBO_ACTION(combo_tab_c),
  [MY_COMBO_TAB_D] = COMBO_ACTION(combo_tab_d),
  [MY_COMBO_TAB_G] = COMBO_ACTION(combo_tab_g),
  [MY_COMBO_TAB_I] = COMBO_ACTION(combo_tab_i),
  [MY_COMBO_TAB_L] = COMBO_ACTION(combo_tab_l),
  [MY_COMBO_TAB_U] = COMBO_ACTION(combo_tab_u),
  [MY_COMBO_AB] = COMBO_ACTION(combo_ab),
  [MY_COMBO_AK] = COMBO_ACTION(combo_ak),
  [MY_COMBO_AM] = COMBO_ACTION(combo_am),
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
  [MY_COMBO_NT] = COMBO_ACTION(combo_nt),
  [MY_COMBO_OW] = COMBO_ACTION(combo_ow),
  [MY_COMBO_RU] = COMBO_ACTION(combo_ru),
  [MY_COMBO_RY] = COMBO_ACTION(combo_ry),
  [MY_COMBO_UY] = COMBO_ACTION(combo_uy),
  COMBO(combo_zx, KC_CUT),
  COMBO(combo_xc, KC_COPY),
  COMBO(combo_cv, KC_PASTE),
  COMBO(combo_zv, KC_UNDO),
};

#define MODS_SHIFT (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define SEND_CAP_STRING(str, capitalized) if (MODS_SHIFT) { \
                                            clear_mods(); \
                                            SEND_STRING(capitalized); \
                                          } else { \
                                            SEND_STRING(str); \
                                          }

void process_combo_event(uint8_t combo_index, bool pressed) {
  switch(combo_index) {
    case MY_COMBO_QUOT_C:
      if (pressed) {
        SEND_CAP_STRING("can't ", "Can't ");
      }
      break;
    case MY_COMBO_QUOT_D:
      if (pressed) {
        SEND_CAP_STRING("don't ", "Don't ");
      }
      break;
    case MY_COMBO_QUOT_H:
      if (pressed) {
        SEND_CAP_STRING("hasn't ", "Hasn't ");
      }
      break;
    case MY_COMBO_QUOT_R:
      if (pressed) {
        SEND_CAP_STRING("aren't ", "Aren't ");
      }
      break;
    case MY_COMBO_QUOT_S:
      if (pressed) {
        SEND_CAP_STRING("isn't ", "Isn't ");
      }
      break;
    case MY_COMBO_QUOT_T:
      if (pressed) {
        SEND_CAP_STRING("it's ", "It's ");
      }
      break;
    case MY_COMBO_QUOT_W:
      if (pressed) {
        SEND_CAP_STRING("won't ", "Won't ");
      }
      break;
    case MY_COMBO_QUOT_Y:
      if (pressed) {
        SEND_CAP_STRING("you're ", "You're ");
      }
      break;
    case MY_COMBO_SLSH_F:
      if (pressed) {
        SEND_CAP_STRING("ftp://", "FTP ");
      }
      break;
    case MY_COMBO_SLSH_H:
      if (pressed) {
        SEND_CAP_STRING("http://", "HTTP ");
      }
      break;
    case MY_COMBO_SLSH_S:
      if (pressed) {
        SEND_CAP_STRING("https://", "HTTPS ");
      }
      break;
    case MY_COMBO_TAB_B:
      if (pressed) {
        // Markdown strong emphasis/bold
        SEND_STRING("****" SS_TAP(X_LEFT) SS_TAP(X_LEFT));
      }
      break;
    case MY_COMBO_TAB_C:
      if (pressed) {
        // Markdown list item with checkbox
        SEND_STRING("- [ ] ");
      }
      break;
    case MY_COMBO_TAB_D:
      if (pressed) {
        // Markdown deletion
        SEND_STRING("~~~~" SS_TAP(X_LEFT) SS_TAP(X_LEFT));
      }
      break;
    case MY_COMBO_TAB_G:
      if (pressed) {
        // Markdown image
        SEND_STRING("![]()" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
      }
      break;
    case MY_COMBO_TAB_I:
      if (pressed) {
        // Markdown emphasis/italic
        SEND_STRING("**" SS_TAP(X_LEFT));
      }
      break;
    case MY_COMBO_TAB_L:
      if (pressed) {
        // Markdown link
        SEND_STRING("[]()" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
      }
      break;
    case MY_COMBO_TAB_U:
      if (pressed) {
        // Markdown emphasis/italic
        SEND_STRING("__" SS_TAP(X_LEFT));
      }
      break;
    case MY_COMBO_AB:
      if (pressed) {
        SEND_CAP_STRING("about ", "About ");
      }
      break;
    case MY_COMBO_AK:
      if (pressed) {
        SEND_STRING("a.k.a. ");
      }
      break;
    case MY_COMBO_AM:
      if (pressed) {
        SEND_STRING("&");
      }
      break;
    case MY_COMBO_AN:
      if (pressed) {
        SEND_CAP_STRING("and ", "And ");
      }
      break;
    case MY_COMBO_AT:
      if (pressed) {
        SEND_STRING("@");
      }
      break;
    case MY_COMBO_AW:
      if (pressed) {
        SEND_CAP_STRING("what ", "What ");
      }
      break;
    case MY_COMBO_BC:
      if (pressed) {
        SEND_CAP_STRING("because ", "Because ");
      }
      break;
    case MY_COMBO_CW:
      if (pressed) {
        SEND_CAP_STRING("which ", "Which ");
      }
      break;
    case MY_COMBO_DL:
      if (pressed) {
        SEND_CAP_STRING("would ", "Would ");
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
        SEND_CAP_STRING("the ", "The ");
      }
      break;
    case MY_COMBO_HV:
      if (pressed) {
        SEND_CAP_STRING("have ", "Have ");
      }
      break;
    case MY_COMBO_IO:
      if (pressed) {
        SEND_STRING("tion "); // Suffix
      }
      break;
    case MY_COMBO_IT:
      if (pressed) {
        SEND_CAP_STRING("this ", "This ");
      }
      break;
    case MY_COMBO_IW:
      if (pressed) {
        SEND_CAP_STRING("with ", "With ");
      }
      break;
    case MY_COMBO_KM:
      if (pressed) {
        SEND_CAP_STRING("make ", "Make ");
      }
      break;
    case MY_COMBO_LT:
      if (pressed) {
        SEND_CAP_STRING("until ", "Until ");
      }
      break;
    case MY_COMBO_LW:
      if (pressed) {
        SEND_CAP_STRING("will ", "Will ");
      }
      break;
    case MY_COMBO_MT:
      if (pressed) {
        SEND_STRING("ment "); // Suffix
      }
      break;
    case MY_COMBO_NT:
      if (pressed) {
        leader_activate_or_cancel();
      }
      break;
    case MY_COMBO_OW:
      if (pressed) {
        SEND_CAP_STRING("without ", "Without ");
      }
      break;
    case MY_COMBO_RU:
      if (pressed) {
        SEND_CAP_STRING("you're ", "You're ");
      }
      break;
    case MY_COMBO_RY:
      if (pressed) {
        SEND_CAP_STRING("your ", "Your ");
      }
      break;
    case MY_COMBO_UY:
      if (pressed) {
        SEND_CAP_STRING("you ", "You ");
      }
      break;
  }
}
