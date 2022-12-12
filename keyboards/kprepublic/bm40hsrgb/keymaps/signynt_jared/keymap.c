// qmk flash -kb bm40hsrgb -km signynt_jared

/* Copyright 2021 Vincenzo Mitchell Barroso
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

// Tap Dance keycodes
enum td_keycodes {
    ALT_LP, // Our example key: `LALT` when held, `(` when tapped. Add additional keycodes for each tapdance.
};

// Define a type containing as many tapdance states as you need
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_SINGLE_TAP
} td_state_t;

// Create a global instance of the tapdance state type
static td_state_t td_state;

// Declare your tapdance functions:

// Function to determine the current tapdance state
td_state_t cur_dance(qk_tap_dance_state_t *state);

// `finished` and `reset` functions for each tapdance keycode
void altlp_finished(qk_tap_dance_state_t *state, void *user_data);
void altlp_reset(qk_tap_dance_state_t *state, void *user_data);

//define layers
enum layers {BASE, NAV, NSL, FUN};

//layer led colors
bool rgb_matrix_indicators_user(void) {

    //layer indicators

    if(IS_LAYER_ON(NAV)) {
    rgb_matrix_set_color(40, 0, 40, 50);

    rgb_matrix_set_color(19, 0, 40, 50);
    rgb_matrix_set_color(20, 0, 40, 50);
    rgb_matrix_set_color(21, 0, 40, 50);
    rgb_matrix_set_color(22, 0, 40, 50);
    }

    if(IS_LAYER_ON(FUN)) {
    rgb_matrix_set_color(43, 50, 0, 0);

    rgb_matrix_set_color(1, 50, 0, 0);
    rgb_matrix_set_color(2, 50, 0, 0);
    rgb_matrix_set_color(3, 50, 0, 0);
    rgb_matrix_set_color(4, 50, 0, 0);

    rgb_matrix_set_color(13, 50, 0, 0);
    rgb_matrix_set_color(14, 50, 0, 0);
    rgb_matrix_set_color(15, 50, 0, 0);
    rgb_matrix_set_color(16, 50, 0, 0);

    rgb_matrix_set_color(25, 50, 0, 0);
    rgb_matrix_set_color(26, 50, 0, 0);
    rgb_matrix_set_color(27, 50, 0, 0);
    rgb_matrix_set_color(28, 50, 0, 0);
    }

    if(IS_LAYER_ON(NSL)) {
    rgb_matrix_set_color(42, 10, 0, 50);

    rgb_matrix_set_color(2, 10, 0, 50);
    rgb_matrix_set_color(3, 10, 0, 50);
    rgb_matrix_set_color(4, 10, 0, 50);

    rgb_matrix_set_color(14, 10, 0, 50);
    rgb_matrix_set_color(15, 10, 0, 50);
    rgb_matrix_set_color(16, 10, 0, 50);

    rgb_matrix_set_color(26, 10, 0, 50);
    rgb_matrix_set_color(27, 10, 0, 50);
    rgb_matrix_set_color(28, 10, 0, 50);

    rgb_matrix_set_color(38, 10, 0, 50);
    rgb_matrix_set_color(39, 10, 0, 50);
    rgb_matrix_set_color(40, 10, 0, 50);
    }

    //capslock leds

    if (host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK)) {
        rgb_matrix_set_color_all(50, 15.6, 0);
    }

    return false;
}

//  qmk compile -kb kprepublic/bm40hsrgb -km signynt_jared
//
//    _______________  _______________  _______________  _______________  _______x_______  _______________  _______________  _______x_______  _______________  _______________  _______________  _______________
//    1,               2,               3,               4,               5,               6,               7,               8,               9,               10,              11,              12,
//    13,              14,              15,              16,              17,              18,              19,              20,              21,              22,              23,              24,
//    25,              26,              27,              28,              29,              30,              31,              32,              33,              34,              35,              36,
//    37,              38,              39,              40,              41,                               42,              43,              44,              45,              46,              47,
//

//base
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//  layer 0
//  _______________  _______________  _______________  _______________  _______x_______  _______________  _______________  _______x_______  _______________  _______________  _______________  _______________
  [BASE] = LAYOUT_planck_mit(
    KC_ESC,          KC_Q,            KC_W,            KC_E,            KC_R,            KC_T,            KC_Y,            KC_U,            KC_I,            KC_O,            KC_P,            KC_LGUI,
    LSFT_T(KC_CAPS), KC_A,            KC_S,            KC_D,            KC_F,            KC_G,            KC_H,            KC_J,            KC_K,            KC_L,            KC_SCLN,         KC_QUOT,
    KC_LCTL,         KC_Z,            KC_X,            KC_C,            KC_V,            KC_B,            KC_N,            KC_M,            KC_COMM,         KC_DOT,          KC_SLSH,         KC_RCTL,
    KC_APP,          TG(NAV),         KC_LALT,         KC_DEL,          KC_BSPC,                          KC_SPC,          KC_ENT,          KC_TAB,          _______,         OSL(FUN),        TG(NSL)
  ),

//layers 1
//  _______________  _______________  _______________  _______________  _______x_______  _______________  _______________  _______x_______  _______________  _______________  _______________  _______________
  [NAV] = LAYOUT_planck_mit(
    TG(BASE),        KC_MUTE,         KC_MUTE,         KC_MSTP,         KC_MPLY,         RGB_VAI,         KC_HOME,         KC_PGDN,         KC_PGUP,         KC_END,          KC_INS,          KC_LGUI,
    KC_LSFT,         KC_MPRV,         KC_VOLD,         KC_VOLU,         KC_MNXT,         RGB_VAD,         KC_LEFT,         KC_DOWN,         KC_UP,           KC_RGHT,         _______,         KC_RSFT,
    KC_LCTL,         RGB_TOG,          RGB_MOD,        RGB_HUI,         RGB_SAI,         RGB_VAI,         _______,         _______,         _______,         _______,         _______,         KC_RCTL,
    _______,         TG(NAV),         _______,         KC_DEL,          KC_BSPC,                          _______,         _______,         _______,         _______,         OSL(FUN),        _______
  ),
// layer 2
//  _______________  _______________  _______________  _______________  _______x_______  _______________  _______________  _______x_______  _______________  _______________  _______________  _______________
  [FUN] = LAYOUT_planck_mit(
    KC_TILD,          KC_LBRC,        KC_EXLM,         KC_AT,           KC_RBRC,         KC_BACKSLASH,    KC_PLUS,         KC_F7,           KC_F8,           KC_F9,           KC_F12,          _______,
    KC_GRAVE,         KC_LCBR,        KC_HASH,         KC_DLR,          KC_RCBR,         KC_SLASH,        KC_EQUAL,        KC_F4,           KC_F5,           KC_F6,           KC_F11,          KC_PSCR,
    KC_PIPE,          KC_LPRN,        KC_PERC,         KC_CIRC,         KC_RPRN,         KC_QUESTION,     _______,         KC_F1,           KC_F2,           KC_F3,           KC_F10,          KC_PAUS,
    _______,          KC_UNDERSCORE,  KC_AMPR,         KC_ASTR,         KC_MINUS,                         _______,         _______,         _______,         _______,         _______,         _______
  ),
//  layer 3
//  _______________  _______________  _______________  _______________  _______x_______  _______________  _______________  _______x_______  _______________  _______________  _______________  _______________
  [NSL] = LAYOUT_planck_mit(
    TG(BASE),        _______,        _______,          _______,         _______,         _______,         _______,         KC_7,            KC_8,            KC_9,            KC_MINUS,        KC_BSPC,
    _______,         _______,        _______,          _______,         _______,         _______,         _______,         KC_4,            KC_5,            KC_6,            KC_EQL,          KC_LSFT,
    _______,         _______,        _______,          _______,         _______,         _______,         _______,         KC_1,            KC_2,            KC_3,            _______,         _______,
    QK_BOOT,         TG(NAV),        _______,          KC_DEL,          KC_BSPC,                          KC_SPC,          KC_0,         _______,            KC_DOT,          OSL(FUN),         _______
  )
};


// Determine the tapdance state to return
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }

    if (state->count == 2) return TD_DOUBLE_SINGLE_TAP;
    else return TD_UNKNOWN; // Any number higher than the maximum state value you return above
}

// Handle the possible states for each tapdance keycode you define:

void altlp_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code16(KC_LPRN);
            break;
        case TD_SINGLE_HOLD:
            register_mods(MOD_BIT(KC_LALT)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        case TD_DOUBLE_SINGLE_TAP: // Allow nesting of 2 parens `((` within tapping term
            tap_code16(KC_LPRN);
            register_code16(KC_LPRN);
            break;
        default:
            break;
    }
}

void altlp_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            unregister_code16(KC_LPRN);
            break;
        case TD_SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_LALT)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            break;
        case TD_DOUBLE_SINGLE_TAP:
            unregister_code16(KC_LPRN);
            break;
        default:
            break;
    }
}

// Define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions
qk_tap_dance_action_t tap_dance_actions[] = {
    [ALT_LP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, altlp_finished, altlp_reset)
};
