/*
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
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

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_LOWER,
    LAYER_RAISE,
    LAYER_MOUSE,
    LAYER_GAME
};

#define BASE TO(LAYER_BASE)
#define LOWER MO(LAYER_LOWER)
#define RAISE MO(LAYER_RAISE)
#define GAMING TO(LAYER_GAME)

const uint16_t PROGMEM tab_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM enter_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM scroll_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM caps_combo[] = {KC_A, KC_S, KC_D, COMBO_END};

combo_t key_combos[] = {
    COMBO(tab_combo, KC_TAB),
    COMBO(enter_combo, KC_ENT),
    COMBO(scroll_combo, QK_KB_7),
    COMBO(caps_combo, KC_CAPS)
};

void pointing_device_init_user(void) {
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_split_3x5_3(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
          KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_QUOT,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                           KC_RSFT,   LOWER,  KC_SPC,    KC_BSPC,  RAISE, KC_LCTL
  //                   ╰───────────────────────────╯ ╰──────────────────╯

  ),

  [1] = LAYOUT_split_3x5_3(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
        KC_GRV, XXXXXXX, KC_RBRC, KC_LBRC, XXXXXXX,    XXXXXXX,    KC_7,    KC_8,    KC_9, KC_MINS,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       XXXXXXX, KC_SCLN, KC_RPRN, KC_LPRN, XXXXXXX,    XXXXXXX,    KC_4,    KC_5,    KC_6, KC_EQL,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, KC_COLN, XXXXXXX, XXXXXXX,    XXXXXXX,    KC_1,    KC_2,    KC_3, KC_DOT,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         KC_RSFT, XXXXXXX, XXXXXXX,    KC_RSFT,    KC_0, KC_DOT
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [2] = LAYOUT_split_3x5_3(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
      KC_ESC, KC_LGUI, KC_ESC, A(KC_F4), QK_KB_1,   C(KC_Y), XXXXXXX,  KC_MUTE, KC_VOLD, KC_VOLU,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       C(KC_A), C(KC_S), KC_DEL,  C(KC_F), XXXXXXX,    KC_PGUP, KC_HOME,    KC_UP,  KC_END, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       C(KC_Z), C(KC_X), C(KC_C), C(KC_V), QK_KB_0,    KC_PGDN, KC_LEFT,  KC_DOWN, KC_RGHT, C(KC_SLSH),
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         KC_RSFT, KC_RCTL, XXXXXXX,    KC_BSPC, XXXXXXX, XXXXXXX
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [3] = LAYOUT_split_3x5_3(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_BTN1, KC_BTN2, KC_BTN2, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_BTN1, KC_BTN2, KC_BTN2, XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         KC_LSFT, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [4] = LAYOUT_split_3x5_3(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX,    XXXXXXX,  KC_ESC, KC_F, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    XXXXXXX,    BASE, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_LSFT,    KC_A,     KC_S,   KC_D,    KC_F,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         KC_G,    KC_V,  KC_SPC,    XXXXXXX, XXXXXXX, XXXXXXX
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  )
};
