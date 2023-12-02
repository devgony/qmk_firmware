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

// Tap Dance definitions
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Tap dance enums
enum {
    Q_1,
    W_2,
    E_3,
    R_4,
    T_5,
    Y_6,
    U_7,
    I_8,
    O_9,
    P_0,
};

td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

static td_tap_t tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void q_finished(tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_Q); break;
        case TD_SINGLE_HOLD: register_code16(LSFT(KC_Q)); break;
        case TD_DOUBLE_TAP: register_code(KC_1); break;
        case TD_DOUBLE_HOLD: register_code16(LSFT(KC_1)); break;
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_Q); register_code(KC_Q); break;
        default: break;
    }
}

void q_reset(tap_dance_state_t *state, void *user_data) {
    switch (tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_Q); break;
        case TD_SINGLE_HOLD: unregister_code16(LSFT(KC_Q)); break;
        case TD_DOUBLE_TAP: unregister_code(KC_1); break;
        case TD_DOUBLE_HOLD: unregister_code16(LSFT(KC_1)); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_Q); break;
        default: break;
    }
    tap_state.state = TD_NONE;
}

void w_finished(tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_W); break;
        case TD_SINGLE_HOLD: register_code16(LSFT(KC_W)); break;
        case TD_DOUBLE_TAP: register_code(KC_2); break;
        case TD_DOUBLE_HOLD: register_code16(LSFT(KC_2)); break;
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_W); register_code(KC_W); break;
        default: break;
    }
}

void w_reset(tap_dance_state_t *state, void *user_data) {
    switch (tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_W); break;
        case TD_SINGLE_HOLD: unregister_code16(LSFT(KC_W)); break;
        case TD_DOUBLE_TAP: unregister_code(KC_2); break;
        case TD_DOUBLE_HOLD: unregister_code16(LSFT(KC_2)); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_W); break;
        default: break;
    }
    tap_state.state = TD_NONE;
}

void e_finished(tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_E); break;
        case TD_SINGLE_HOLD: register_code16(LSFT(KC_E)); break;
        case TD_DOUBLE_TAP: register_code(KC_3); break;
        case TD_DOUBLE_HOLD: register_code16(LSFT(KC_3)); break;
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_E); register_code(KC_E); break;
        default: break;
    }
}

void e_reset(tap_dance_state_t *state, void *user_data) {
    switch (tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_E); break;
        case TD_SINGLE_HOLD: unregister_code16(LSFT(KC_E)); break;
        case TD_DOUBLE_TAP: unregister_code(KC_3); break;
        case TD_DOUBLE_HOLD: unregister_code16(LSFT(KC_3)); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_E); break;
        default: break;
    }
    tap_state.state = TD_NONE;
}

void r_finished(tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_R); break;
        case TD_SINGLE_HOLD: register_code16(LSFT(KC_R)); break;
        case TD_DOUBLE_TAP: register_code(KC_4); break;
        case TD_DOUBLE_HOLD: register_code16(LSFT(KC_4)); break;
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_R); register_code(KC_R); break;
        default: break;
    }
}

void r_reset(tap_dance_state_t *state, void *user_data) {
    switch (tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_R); break;
        case TD_SINGLE_HOLD: unregister_code16(LSFT(KC_R)); break;
        case TD_DOUBLE_TAP: unregister_code(KC_4); break;
        case TD_DOUBLE_HOLD: unregister_code16(LSFT(KC_4)); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_R); break;
        default: break;
    }
    tap_state.state = TD_NONE;
}

void t_finished(tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_T); break;
        case TD_SINGLE_HOLD: register_code16(LSFT(KC_T)); break;
        case TD_DOUBLE_TAP: register_code(KC_5); break;
        case TD_DOUBLE_HOLD: register_code16(LSFT(KC_5)); break;
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_T); register_code(KC_T); break;
        default: break;
    }
}

void t_reset(tap_dance_state_t *state, void *user_data) {
    switch (tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_T); break;
        case TD_SINGLE_HOLD: unregister_code16(LSFT(KC_T)); break;
        case TD_DOUBLE_TAP: unregister_code(KC_5); break;
        case TD_DOUBLE_HOLD: unregister_code16(LSFT(KC_5)); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_T); break;
        default: break;
    }
    tap_state.state = TD_NONE;
}

void y_finished(tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_Y); break;
        case TD_SINGLE_HOLD: register_code16(LSFT(KC_Y)); break;
        case TD_DOUBLE_TAP: register_code(KC_6); break;
        case TD_DOUBLE_HOLD: register_code16(LSFT(KC_6)); break;
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_Y); register_code(KC_Y); break;
        default: break;
    }
}

void y_reset(tap_dance_state_t *state, void *user_data) {
    switch (tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_Y); break;
        case TD_SINGLE_HOLD: unregister_code16(LSFT(KC_Y)); break;
        case TD_DOUBLE_TAP: unregister_code(KC_6); break;
        case TD_DOUBLE_HOLD: unregister_code16(LSFT(KC_6)); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_Y); break;
        default: break;
    }
    tap_state.state = TD_NONE;
}

void u_finished(tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_U); break;
        case TD_SINGLE_HOLD: register_code16(LSFT(KC_U)); break;
        case TD_DOUBLE_TAP: register_code(KC_7); break;
        case TD_DOUBLE_HOLD: register_code16(LSFT(KC_7)); break;
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_U); register_code(KC_U); break;
        default: break;
    }
}

void u_reset(tap_dance_state_t *state, void *user_data) {
    switch (tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_U); break;
        case TD_SINGLE_HOLD: unregister_code16(LSFT(KC_U)); break;
        case TD_DOUBLE_TAP: unregister_code(KC_7); break;
        case TD_DOUBLE_HOLD: unregister_code16(LSFT(KC_7)); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_U); break;
        default: break;
    }
    tap_state.state = TD_NONE;
}

void i_finished(tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_I); break;
        case TD_SINGLE_HOLD: register_code16(LSFT(KC_I)); break;
        case TD_DOUBLE_TAP: register_code(KC_8); break;
        case TD_DOUBLE_HOLD: register_code16(LSFT(KC_8)); break;
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_I); register_code(KC_I); break;
        default: break;
    }
}

void i_reset(tap_dance_state_t *state, void *user_data) {
    switch (tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_I); break;
        case TD_SINGLE_HOLD: unregister_code16(LSFT(KC_I)); break;
        case TD_DOUBLE_TAP: unregister_code(KC_8); break;
        case TD_DOUBLE_HOLD: unregister_code16(LSFT(KC_8)); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_I); break;
        default: break;
    }
    tap_state.state = TD_NONE;
}

void o_finished(tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_O); break;
        case TD_SINGLE_HOLD: register_code16(LSFT(KC_O)); break;
        case TD_DOUBLE_TAP: register_code(KC_9); break;
        case TD_DOUBLE_HOLD: register_code16(LSFT(KC_9)); break;
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_O); register_code(KC_O); break;
        default: break;
    }
}

void o_reset(tap_dance_state_t *state, void *user_data) {
    switch (tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_O); break;
        case TD_SINGLE_HOLD: unregister_code16(LSFT(KC_O)); break;
        case TD_DOUBLE_TAP: unregister_code(KC_9); break;
        case TD_DOUBLE_HOLD: unregister_code16(LSFT(KC_9)); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_O); break;
        default: break;
    }
    tap_state.state = TD_NONE;
}

void p_finished(tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_P); break;
        case TD_SINGLE_HOLD: register_code16(LSFT(KC_P)); break;
        case TD_DOUBLE_TAP: register_code(KC_0); break;
        case TD_DOUBLE_HOLD: register_code16(LSFT(KC_0)); break;
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_P); register_code(KC_P); break;
        default: break;
    }
}

void p_reset(tap_dance_state_t *state, void *user_data) {
    switch (tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_P); break;
        case TD_SINGLE_HOLD: unregister_code16(LSFT(KC_P)); break;
        case TD_DOUBLE_TAP: unregister_code(KC_0); break;
        case TD_DOUBLE_HOLD: unregister_code16(LSFT(KC_0)); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_P); break;
        default: break;
    }
    tap_state.state = TD_NONE;
}

tap_dance_action_t tap_dance_actions[] = {
    [Q_1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, q_finished, q_reset),
    [W_2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, w_finished, w_reset),
    [E_3] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, e_finished, e_reset),
    [R_4] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, r_finished, r_reset),
    [T_5] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, t_finished, t_reset),
    [Y_6] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, y_finished, y_reset),
    [U_7] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, u_finished, u_reset),
    [I_8] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, i_finished, i_reset),
    [O_9] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, o_finished, o_reset),
    [P_0] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, p_finished, p_reset)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    TD(Q_1), TD(W_2), TD(E_3), TD(R_4), TD(T_5),         TD(Y_6), TD(U_7), TD(I_8), TD(O_9), TD(P_0),
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
