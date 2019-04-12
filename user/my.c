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
#include "private.h"

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
#ifdef STENO_ENABLE
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
#endif
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

LEADER_DICT {
  LEADER(KC_H, KC_A) {
    SEND_STRING("&amp;");
    return leader_terminate();
  }

  LEADER(KC_H, KC_E) {
    SEND_STRING("&hellip;");
    return leader_terminate();
  }

  LEADER(KC_H, KC_Q) {
    SEND_STRING("&quot;");
    return leader_terminate();
  }

  LEADER(KC_H, KC_SPC) {
    SEND_STRING("&nbsp;");
    return leader_terminate();
  }

  LEADER(KC_H, KC_R) {
    SEND_STRING("&reg;");
    return leader_terminate();
  }

  LEADER(KC_H, KC_T) {
    SEND_STRING("&trade;");
    return leader_terminate();
  }

  LEADER(KC_H, KC_C) {
    SEND_STRING("&copy;");
    return leader_terminate();
  }

  LEADER(KC_H, KC_COMM) {
    SEND_STRING("&lt;");
    return leader_terminate();
  }

  LEADER(KC_H, KC_DOT) {
    SEND_STRING("&gt;");
    return leader_terminate();
  }

  LEADER(KC_H, KC_X) {
    SEND_STRING("&times;");
    return leader_terminate();
  }

  LEADER(KC_SPC, KC_SPC) {
    layer_off(CAMEL_LAYER);
    layer_off(KEBAB_LAYER);
    layer_off(SNAKE_LAYER);
    return leader_terminate();
  }

  LEADER(KC_SPC, KC_C) {
    layer_on(CAMEL_LAYER);
    return leader_terminate();
  }

  LEADER(KC_SPC, KC_K) {
    layer_on(KEBAB_LAYER);
    return leader_terminate();
  }

  LEADER(KC_SPC, KC_S) {
    layer_on(SNAKE_LAYER);
    return leader_terminate();
  }

#ifdef PRIVATE_MACROS
  LEADER(KC_D, KC_E) {
    SEND_STRING(PRIVATE_DOMAIN_EMAIL);
    return leader_terminate();
  }

  LEADER(KC_D, KC_G) {
    SEND_STRING(PRIVATE_DOMAIN_GENERIC);
    return leader_terminate();
  }

  LEADER(KC_D, KC_P) {
    SEND_STRING(PRIVATE_DOMAIN_PERSONAL);
    return leader_terminate();
  }

  LEADER(KC_D, KC_W) {
    SEND_STRING(PRIVATE_DOMAIN_WORK);
    return leader_terminate();
  }

  LEADER(KC_M, KC_P) {
    SEND_STRING(PRIVATE_EMAIL_PERSONAL);
    return leader_terminate();
  }

  LEADER(KC_M, KC_S) {
    SEND_STRING(PRIVATE_EMAIL_SUPPORT);
    return leader_terminate();
  }

  LEADER(KC_M, KC_W) {
    SEND_STRING(PRIVATE_EMAIL_WORK);
    return leader_terminate();
  }

  LEADER(KC_F, KC_P) {
    SEND_STRING(PRIVATE_FINGERPRINT_PERSONAL);
    return leader_terminate();
  }

  LEADER(KC_F, KC_W) {
    SEND_STRING(PRIVATE_FINGERPRINT_WORK);
    return leader_terminate();
  }

  LEADER(KC_K, KC_P) {
    SEND_STRING(PRIVATE_KEYID_PERSONAL);
    return leader_terminate();
  }

  LEADER(KC_K, KC_W) {
    SEND_STRING(PRIVATE_KEYID_WORK);
    return leader_terminate();
  }

  LEADER(KC_L, KC_B) {
    SEND_STRING(PRIVATE_LINK_BLOG);
    return leader_terminate();
  }

  LEADER(KC_L, KC_D) {
    SEND_STRING(PRIVATE_LINK_DOCS);
    return leader_terminate();
  }

  LEADER(KC_L, KC_K) {
    SEND_STRING(PRIVATE_LINK_KEYMAP);
    return leader_terminate();
  }

  LEADER(KC_L, KC_Q) {
    SEND_STRING(PRIVATE_LINK_QMK);
    return leader_terminate();
  }

  LEADER(KC_P, KC_P) {
    SEND_STRING(PRIVATE_PHONE_PERSONAL);
    return leader_terminate();
  }

  LEADER(KC_P, KC_W) {
    SEND_STRING(PRIVATE_PHONE_WORK);
    return leader_terminate();
  }

  LEADER(KC_U, KC_P) {
    SEND_STRING(PRIVATE_USERNAME_PERSONAL);
    return leader_terminate();
  }

  LEADER(KC_U, KC_W) {
    SEND_STRING(PRIVATE_USERNAME_WORK);
    return leader_terminate();
  }
#endif

  return false;
}

#ifdef COMBO_ENABLE
enum combo_events {
  MY_COMBO_AN,
  MY_COMBO_AT,
  MY_COMBO_AW,
  MY_COMBO_CW,
  MY_COMBO_DL,
  MY_COMBO_EG,
  MY_COMBO_EI,
  MY_COMBO_HT,
  MY_COMBO_HV,
  MY_COMBO_IO,
  MY_COMBO_IT,
  MY_COMBO_KM,
  MY_COMBO_LT,
  MY_COMBO_LW,
  MY_COMBO_UY,
};

const uint16_t PROGMEM combo_an[] = { KC_A, KC_N, COMBO_END };
const uint16_t PROGMEM combo_at[] = { KC_A, KC_T, COMBO_END };
const uint16_t PROGMEM combo_aw[] = { KC_A, KC_W, COMBO_END };
const uint16_t PROGMEM combo_cw[] = { KC_C, KC_W, COMBO_END };
const uint16_t PROGMEM combo_dl[] = { KC_D, KC_L, COMBO_END };
const uint16_t PROGMEM combo_eg[] = { KC_E, KC_G, COMBO_END };
const uint16_t PROGMEM combo_ei[] = { KC_E, KC_I, COMBO_END };
const uint16_t PROGMEM combo_ht[] = { KC_H, KC_T, COMBO_END };
const uint16_t PROGMEM combo_hv[] = { KC_H, KC_V, COMBO_END };
const uint16_t PROGMEM combo_io[] = { KC_I, KC_O, COMBO_END };
const uint16_t PROGMEM combo_it[] = { KC_I, KC_T, COMBO_END };
const uint16_t PROGMEM combo_km[] = { KC_K, KC_M, COMBO_END };
const uint16_t PROGMEM combo_lt[] = { KC_L, KC_T, COMBO_END };
const uint16_t PROGMEM combo_lw[] = { KC_L, KC_W, COMBO_END };
const uint16_t PROGMEM combo_uy[] = { KC_U, KC_Y, COMBO_END };

combo_t key_combos[COMBO_COUNT] = {
  [MY_COMBO_AN] = COMBO_ACTION(combo_an),
  [MY_COMBO_AT] = COMBO_ACTION(combo_at),
  [MY_COMBO_AW] = COMBO_ACTION(combo_aw),
  [MY_COMBO_CW] = COMBO_ACTION(combo_cw),
  [MY_COMBO_DL] = COMBO_ACTION(combo_dl),
  [MY_COMBO_EG] = COMBO_ACTION(combo_eg),
  [MY_COMBO_EI] = COMBO_ACTION(combo_ei),
  [MY_COMBO_HT] = COMBO_ACTION(combo_ht),
  [MY_COMBO_HV] = COMBO_ACTION(combo_hv),
  [MY_COMBO_IO] = COMBO_ACTION(combo_io),
  [MY_COMBO_IT] = COMBO_ACTION(combo_it),
  [MY_COMBO_KM] = COMBO_ACTION(combo_km),
  [MY_COMBO_LT] = COMBO_ACTION(combo_lt),
  [MY_COMBO_LW] = COMBO_ACTION(combo_lw),
  [MY_COMBO_UY] = COMBO_ACTION(combo_uy),
};

void process_combo_event(uint8_t combo_index, bool pressed) {
  switch(combo_index) {
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
        SEND_STRING("tion ");
      }
      break;
    case MY_COMBO_IT:
      if (pressed) {
        SEND_STRING("this ");
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
    case MY_COMBO_UY:
      if (pressed) {
        SEND_STRING("you ");
      }
      break;
  }
}
#endif
