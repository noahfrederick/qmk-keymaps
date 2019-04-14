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

#include "my.h"
#include "my_leader.h"
#include "dynamic_macro.h"

#ifdef AUDIO_ENABLE
float plover_song[][2]    = SONG(PLOVER_SOUND);
float plover_gb_song[][2] = SONG(PLOVER_GOODBYE_SOUND);
#endif

void matrix_init_user() {
#ifdef STENO_ENABLE
  steno_set_mode(STENO_MODE_GEMINI);
#endif
}

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, LOWER_LAYER, RAISE_LAYER, ADJUST_LAYER);
}

// Redefine process_record_keymap() in keymap definitions.
__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_record_dynamic_macro(keycode, record)) {
    return false;
  }

  if (!process_leader(keycode, record)) {
    return false;
  }

  if (!process_record_keymap(keycode, record)) {
    return false;
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(QWERTY_LAYER);
      }
      return false;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(COLEMAK_LAYER);
      }
      return false;
    case STCH_EX:
      if (record->event.pressed) {
        layer_off(CAMEL_LAYER);
        layer_off(KEBAB_LAYER);
        layer_off(SNAKE_LAYER);
      }
      return false;
    case STENO:
      if (record->event.pressed) {
#ifdef AUDIO_ENABLE
        stop_all_notes();
        PLAY_SONG(plover_song);
#endif
        layer_off(RAISE_LAYER);
        layer_off(LOWER_LAYER);
        layer_off(ADJUST_LAYER);
        layer_on(STENO_LAYER);
      }
      return false;
    case STN_EXIT:
      if (record->event.pressed) {
#ifdef AUDIO_ENABLE
        PLAY_SONG(plover_gb_song);
#endif
        layer_off(STENO_LAYER);
      }
      return false;
    case SEND_VERSION:
      if (record->event.pressed) {
        SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP "@" QMK_VERSION " (" QMK_BUILDDATE ")");
      }
      return false;
    case SEND_MAKE:
      if (record->event.pressed) {
        SEND_STRING("make " QMK_KEYBOARD ":" QMK_KEYMAP
#if defined(__arm__)
            ":dfu-util"
#elif (defined(BOOTLOADER_DFU) || defined(BOOTLOADER_LUFA_DFU) || defined(BOOTLOADER_QMK_DFU))
            ":dfu"
#elif defined(BOOTLOADER_HALFKAY)
            ":teensy"
#elif defined(BOOTLOADER_CATERINA)
            ":avrdude"
#endif
            SS_TAP(X_ENTER));
      }
      return false;
  }

  return true;
}
