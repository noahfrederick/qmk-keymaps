/* Copyright 2018 Noah Frederick
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
  /* Base layer (Qwerty)
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │Mute │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │  ⇥  │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  '  │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *  Tap for Esc -- │  ⌃  │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  ⌃  │ -- Tap for Enter
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *    Tap for ( -- │  ⇧  │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │  ⇧  │ -- Tap for )
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *    Tap for [ -- │ GUI │Hyper│  ⌥  │  ⌘  │  ↓  │Space│ Nav │  ↑  │  ⌘  │  ⌥  │Hyper│ GUI │ -- Tap for ]
   *                 └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   *                         /         Tap for Backspace __/                       /
   *    Tap for ] [ --------'-----------------------------------------------------'
   */
  [QWERTY_LAYER] = LAYOUT_preonic_grid_wrapper(
    KC_MUTE, __________________BASE_L0__________________, __________________BASE_R0__________________, XXXXXXX,
    KC_TAB,  _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_QUOT,
    CTL_ESC, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, CTL_ENT,
    KC_LSPO, _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, KC_RSPC,
    GUI_L,   HYPER_L, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  NAV_BSP, RAISE,   KC_RGUI, KC_RALT, HYPER_R, GUI_R
  ),

  /* Base layer (Colemak)
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │  Q  │  W  │  F  │  P  │  G  │  J  │  L  │  U  │  Y  │  ;  │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │  A  │  R  │  S  │  T  │  D  │  H  │  N  │  E  │  I  │  O  │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │  Z  │  X  │  C  │  V  │  B  │  K  │  M  │  ,  │  .  │  /  │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */
  [COLEMAK_LAYER] = LAYOUT_preonic_grid_wrapper(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _________________COLEMAK_L1________________, _________________COLEMAK_R1________________, _______,
    _______, _________________COLEMAK_L2________________, _________________COLEMAK_R2________________, _______,
    _______, _________________COLEMAK_L3________________, _________________COLEMAK_R3________________, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  /* Stitching layer (camel)
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │Exit │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │ (⇧) │     │     │     │     │     │     │
   *                 └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */
  [CAMEL_LAYER] = LAYOUT_preonic_grid_wrapper(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    STCH_EX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, CAPITAL, _______, _______, _______, _______, _______, _______
  ),

  /* Stitching layer (kebab)
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │Exit │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │  -  │     │     │     │     │     │     │
   *                 └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */
  [KEBAB_LAYER] = LAYOUT_preonic_grid_wrapper(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    STCH_EX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, KC_MINS, _______, _______, _______, _______, _______, _______
  ),

  /* Stitching layer (snake)
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │Exit │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │  _  │     │     │     │     │     │     │
   *                 └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */
  [SNAKE_LAYER] = LAYOUT_preonic_grid_wrapper(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    STCH_EX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, KC_UNDS, _______, _______, _______, _______, _______, _______
  ),

  /* Numeric layer
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *  Application -- │ ⌘-` │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │  #  │
   *       window    ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *     switcher    │     │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │  -  │  =  │  `  │  \  │  :  │ndash│mdash│  ,  │  .  │  /  │     │
   *                 ├─────┼─────┼─────┼─────╆━━━━━╅─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     ┃     ┃     │     │     │     │     │     │     │
   *                 └─────┴─────┴─────┴─────┺━━━━━┹─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */
  [LOWER_LAYER] = LAYOUT_preonic_grid_wrapper(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    GUI_GRV, _________________LOWER_L1__________________, _________________LOWER_R1__________________, KC_HASH,
    _______, _________________LOWER_L2__________________, _________________LOWER_R2__________________, _______,
    _______, _________________LOWER_L3__________________, _________________LOWER_R3__________________, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  /* Symbol layer
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │ F11 │ F12 │ F13 │ F14 │ F15 │ F16 │ F17 │ F18 │ F19 │ F20 │  #  │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │  !  │  @  │  #  │  $  │  %  │  ^  │  &  │  *  │  {  │  }  │     │ \
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤  |-- Mostly shifted version
   *                 │     │  _  │  +  │  ~  │  |  │  :  │ndash│mdash│  ,  │  .  │  /  │     │ /    of lower layer
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────╆━━━━━╅─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │  Delete   ┃     ┃     │     │     │     │
   *                 └─────┴─────┴─────┴─────┴─────┴─────┴─────┺━━━━━┹─────┴─────┴─────┴─────┘
   */
  [RAISE_LAYER] = LAYOUT_preonic_grid_wrapper(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _________________RAISE_L1__________________, _________________RAISE_R1__________________, KC_HASH,
    _______, _________________RAISE_L2__________________, _________________RAISE_R2__________________, _______,
    _______, _________________RAISE_L3__________________, _________________RAISE_R3__________________, _______,
    _______, _______, _______, _______, _______, KC_DEL,  KC_DEL,  _______, _______, _______, _______, _______
  ),

  /* Directional navigation layer
   *
   *          Large movements -----/```````````````````\   /```````````````````\----- Vim-style arrow keys
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │Home │PgUp │PgDn │ End │  ←  │  ↓  │  ↑  │  →  │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │ ⌘ ← │ ⌘ ↑ │ ⌘ ↓ │ ⌘ → │ ⌥ ← │ ⌥ ↓ │ ⌥ ↑ │ ⌥ → │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────╆━━━━━╅─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     ┃     ┃     │     │     │     │     │
   *                 └─────┴─────┴─────┴─────┴─────┴─────┺━━━━━┹─────┴─────┴─────┴─────┴─────┘
   */
  [NAV_LAYER] = LAYOUT_preonic_grid_wrapper(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    XXXXXXX, __________________NAV_L1___________________, __________________NAV_R1___________________, XXXXXXX,
    _______, __________________NAV_L2___________________, __________________NAV_R2___________________, _______,
    _______, __________________NAV_L3___________________, __________________NAV_R3___________________, _______,
    _______, _______, _______, _______, XXXXXXX, XXXXXXX, NAV_BSP, XXXXXXX, _______, _______, _______, _______
  ),

  /* GUI (window management/mouse/media controls) layer
   *
   *         Mouse keys -----/```````````````````\               /```````````````````\----- Window manager
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │Play │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │Ms B2│Ms Up│Ms B1│Ms WD│     │     │Prev │ NW  │  N  │ NE  │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │Ms L │Ms Dn│Ms R │Ms WU│     │     │Full │  W  │Centr│  E  │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │Undo │ Cut │Copy │Paste│     │     │Next │ SW  │  S  │ SE  │     │
   *                 ┢━━━━━╅─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────╆━━━━━┪
   *                 ┃     ┃Prev │Play │Next │Brig-│Sleep│Wake │Brig+│Mute │Vol- │Vol+ ┃     ┃
   *                 ┗━━━━━┹─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┺━━━━━┛
   *                         \___ Media ___/   \___ Screen/sleep __/   \___ Volume __/
   */
  [GUI_LAYER] = LAYOUT_preonic_grid_wrapper(
    KC_MPLY, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, __________________GUI_L1___________________, __________________GUI_R1___________________, _______,
    _______, __________________GUI_L2___________________, __________________GUI_R2___________________, _______,
    _______, __________________GUI_L3___________________, __________________GUI_R3___________________, _______,
    _______, __________MEDIA__________, KC_BRID, KC_SLEP, KC_WAKE, KC_BRIU, __________VOLUME_________, _______
  ),

  /* Stenography layer
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │  ⇥  │  #  │  #  │  #  │  #  │  #  │  #  │  #  │  #  │  #  │  #  │  #  │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │  ⌃  │     │  T  │  P  │  H  │     ┆     │  F  │  P  │  L  │  T  │  D  │
   *                 ├─────┼╌ S ╌┼─────┼─────┼─────┼╌╌╌╌ * ╌╌╌╌┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │  K  │  W  │  R  │     ┆     │  R  │  B  │  G  │  S  │  Z  │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │Exit │     │  ⌥  │  ⌘  │  A  │  O  │  E  │  U  │  ⌘  │  ⌥  │     │     │
   *                 └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */
  [STENO_LAYER] = LAYOUT_preonic_grid_wrapper(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_TAB,  _________________STENO_L1__________________, _________________STENO_R1___________________________,
    CTL_ESC, _________________STENO_L2__________________, _________________STENO_R2___________________________,
    XXXXXXX, _________________STENO_L3__________________, _________________STENO_R3___________________________,
    STN_EXIT,XXXXXXX, KC_LALT, KC_LGUI, ____STENO_AO____, ____STENO_EU____, KC_RGUI, KC_RALT, XXXXXXX, XXXXXXX
  ),

  /* Keyboard settings layer
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *     Firmware -- │     │Reset│Make │     │     │     │     │     │     │     │Vers │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *          RGB -- │Qwert│U Lnx│U OSX│Mode-│Mode+│Hue -│Hue +│Sat -│Sat +│     │Play1│Rec 1│ -- Record/play macro 1
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *        Audio -- │Colem│Voic-│Voic+│Mus +│Mus -│MIDI+│MIDI-│Aud +│Aud -│     │Play2│Rec 2│ -- Record/play macro 2
   *                 ├─────┼─────┼─────┼─────╆━━━━━╅─────┼─────╆━━━━━╅─────┼─────┼─────┼─────┤
   *                 │Steno│     │Swap │Norm ┃     ┃  Toggle   ┃     ┃Toggl│Brig-│Brig+│Stop │ -- Stop recording macro
   *                 └─────┴─────┴─────┴─────┺━━━━━┹─────┴─────┺━━━━━┹─────┴─────┴─────┴─────┘
   *                Swap GUI/Alt _/________/             \_____________\_ Backlight _/
   */
  [ADJUST_LAYER] = LAYOUT_preonic_grid_wrapper(
    XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX,
    XXXXXXX, RESET,   SEND_MAKE, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SEND_VERSION,    XXXXXXX,
    QWERTY,  UC_M_LN, UC_M_OS,   RGB_RMOD, RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, XXXXXXX, DYN_MACRO_PLAY1, DYN_REC_START1,
    COLEMAK, MUV_DE,  MUV_IN,    MU_ON,    MU_OFF,  MI_ON,   MI_OFF,  AU_ON,   AU_OFF,  XXXXXXX, DYN_MACRO_PLAY2, DYN_REC_START2,
    STENO,   XXXXXXX, AG_SWAP,   AG_NORM,  LOWER,   LIT_TOG, LIT_TOG, RAISE,   LIT_TOG, LIT_DEC, LIT_INC,         DYN_REC_STOP
  )
};

void encoder_update_user(uint8_t index, bool clockwise) {
  if (IS_LAYER_ON(GUI_LAYER)) {
    clockwise ? tap_code(KC_MNXT) : tap_code(KC_MPRV);
  } else {
    clockwise ? tap_code(KC_VOLU) : tap_code(KC_VOLD);
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        layer_on(ADJUST_LAYER);
      } else {
        layer_off(ADJUST_LAYER);
      }
      break;
   }
}
