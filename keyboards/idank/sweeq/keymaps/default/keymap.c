// Copyright 2023 Idan Kamara (@idank)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define MY_A LSFT_T(KC_A)
#define MY_SC RSFT_T(KC_SCLN)
#define MY_F LT(3,KC_F)
#define MY_Z LCTL_T(KC_Z)
#define MY_BSPC MT(MOD_LALT,KC_BSPC)
#define MY_SPC MT(MOD_LGUI,KC_SPC)
#define MY_SLSH RCTL_T(KC_SLSH)
#define MY_DOT RALT_T(KC_DOT)
#define MY_COMM RGUI_T(KC_COMM)
#define MY_F18 LT(1,KC_F18)
#define MY_ENT LT(2,KC_ENT)

enum combos {
  JK_ESC
};

const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};

combo_t key_combos[] = {
  [JK_ESC] = COMBO(jk_combo, KC_ESC),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,  KC_I,    KC_O,   KC_P,
    MY_A,    KC_S,    KC_D,    MY_F,    KC_G,            KC_H,    KC_J,  KC_K,    KC_L,   MY_SC,
    MY_Z,    KC_X,    KC_C,    KC_V,    KC_B,            KC_N,    KC_M,  MY_COMM, MY_DOT, MY_SLSH,
                                    MY_BSPC, MY_SPC, MY_F18, MY_ENT
  ),
  [1] = LAYOUT(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_TRNS, KC_GRV,  KC_GRV,  KC_NO,   KC_NO,           KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_QUOT,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_NO,           KC_ESC,  KC_BSLS, KC_TRNS, KC_TRNS, KC_TRNS,
                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [2] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_TRNS,  KC_TAB, KC_TRNS, KC_TRNS, KC_TRNS,         KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_ENT,
                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [3] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOTLOADER,   KC_BRID,    KC_BRIU, KC_MUTE, KC_VOLD, KC_VOLU,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_MS_BTN3, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                    KC_TRNS, KC_TRNS, KC_MS_BTN1, KC_MS_BTN2
  )
};
