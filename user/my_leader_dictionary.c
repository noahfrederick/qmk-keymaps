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

#include "my_leader.h"
#ifdef PRIVATE_MACROS
#include "private.h"
#endif

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
