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

#pragma once

#include "my_combos_config.h"

// Disable action_get_macro and fn_actions, since we don't use these
// and it saves on space in the firmware.
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#ifdef AUDIO_ENABLE
// Play sounds when the default layer is set.
#define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                              SONG(COLEMAK_SOUND) }
#endif

#define DYNAMIC_MACRO_SIZE 128

// Delay needed for rotary encoder to trigger media keys
#define TAP_CODE_DELAY 10

#ifdef TAPPING_TERM
#undef TAPPING_TERM
#endif

#define TAPPING_TERM 150
#define TAPPING_TERM_PER_KEY
