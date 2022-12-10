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

// non-KC_ keycodes
#define KC_RST RESET
#define KC_TOG RGB_TOG
#define KC_MOD RGB_MOD
#define KC_HUI RGB_HUI
#define KC_SAI RGB_SAI
#define KC_VAI RGB_VAI

//define layers
enum layers {BASE, MED, NAV, NSSL, NSL, FUN};

enum custom_keycodes {
  CMD_TAB = SAFE_RANGE,
};

bool is_cmd_tab_active = false;
uint16_t cmd_tab_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CMD_TAB:
      if (record->event.pressed) {
        if (!is_cmd_tab_active) {
          is_cmd_tab_active = true;
          register_code(KC_LALT);
        }
        cmd_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;
  }
  return true;
}

void matrix_scan_user(void) {
  if (is_cmd_tab_active) {
    if (timer_elapsed(cmd_tab_timer) > 500) {
      unregister_code(KC_LALT);
      is_cmd_tab_active = false;
    }
  }
}

//layer led colors

void rgb_matrix_indicators_user(void) {

    //layer indicators

    if(IS_LAYER_ON(NAV)) {
    rgb_matrix_set_color(40, 0, 40, 50);

    rgb_matrix_set_color(19, 0, 40, 50);
    rgb_matrix_set_color(20, 0, 40, 50);
    rgb_matrix_set_color(21, 0, 40, 50);
    rgb_matrix_set_color(22, 0, 40, 50);
    }

    if(IS_LAYER_ON(MED)) {
    rgb_matrix_set_color(39, 50, 10, 20);

    rgb_matrix_set_color(19, 50, 10, 20);

    rgb_matrix_set_color(22, 50, 10, 20);

    rgb_matrix_set_color(42, 50, 10, 20);
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

    if(IS_LAYER_ON(NSSL)) {
    rgb_matrix_set_color(41, 0, 50, 1.9);

    rgb_matrix_set_color(1, 0, 50, 1.9);
    rgb_matrix_set_color(2, 0, 50, 1.9);
    rgb_matrix_set_color(3, 0, 50, 1.9);
    rgb_matrix_set_color(4, 0, 50, 1.9);
    rgb_matrix_set_color(5, 0, 50, 1.9);

    rgb_matrix_set_color(13, 0, 50, 1.9);
    rgb_matrix_set_color(14, 0, 50, 1.9);
    rgb_matrix_set_color(15, 0, 50, 1.9);
    rgb_matrix_set_color(16, 0, 50, 1.9);
    rgb_matrix_set_color(17, 0, 50, 1.9);

    rgb_matrix_set_color(25, 0, 50, 1.9);
    rgb_matrix_set_color(26, 0, 50, 1.9);
    rgb_matrix_set_color(27, 0, 50, 1.9);
    rgb_matrix_set_color(28, 0, 50, 1.9);
    rgb_matrix_set_color(29, 0, 50, 1.9);

    }

    //capslock leds

    if (host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK)) {
        rgb_matrix_set_color_all(50, 15.6, 0);
    }

}

//  qmk compile -kb kprepublic/bm40hsrgb -km signynt_jaredS

//--------------------------------------------------------------------------------------------------------

//base
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//  layer 0_______________  _______________  _______________  _______________  _______x_______  _______________  _______________  _______x_______  _______________  _______________  _______________  _______________
  [BASE] = LAYOUT_planck_mit(
    KC_ESC,          KC_Q,            KC_W,            KC_E,            KC_R,            KC_T,            KC_Y,            KC_U,            KC_I,            KC_O,            KC_P,            KC_LGUI,
    LSFT_T(KC_CAPS), KC_A,            KC_S,            KC_D,            KC_F,            KC_G,            KC_H,            KC_J,            KC_K,            KC_L,            KC_SCOLON,       KC_QUOT,
    SC_LCPO,         KC_Z,            KC_X,            KC_C,            KC_V,            KC_B,            KC_N,            KC_M,            KC_COMM,         KC_DOT,          KC_SLSH,         SC_RCPO,
    CMD_TAB,         KC_NO,     KC_RALT,          KC_TAB,         LT(NAV, KC_BSPC),                 KC_DEL,         LT(FUN, KC_SPC), LT(NSL, KC_ENT), KC_NO,         KC_APP,          CMD_TAB
  ),

//layers 1
//  _______________  _______________  _______________  _______________  _______x_______  _______________  _______________  _______x_______  _______________  _______________  _______________  _______________
  [NAV] = LAYOUT_planck_mit(
    _______,         KC_RST,          KC_NO,           KC_MUTE,           KC_NO,           KC_NO,           KC_INS,          KC_HOME,         KC_NO,           KC_END,          KC_PGUP,         KC_LGUI,
    LSFT_T(KC_CAPS), KC_MPRV,         KC_VOLD,         KC_VOLU,         KC_MNXT,         RGB_VAI,           KC_LEFT,         KC_DOWN,         KC_UP,           KC_RGHT,         KC_PGDN,         KC_LSFT,
    SC_LCPO,         KC_TOG,          KC_MOD,          KC_HUI,          KC_SAI,          KC_VAI,          KC_NO,           KC_NO,           KC_NO,           KC_NO,           KC_NO,           SC_RCPO,
    _______,         _______,         _______,         _______,         _______,                      KC_MSTP,              KC_MPLY,          _______,          _______,         _______,         _______
  ),
// layer 2
//  _______________  _______________  _______________  _______________  _______x_______  _______________  _______________  _______x_______  _______________  _______________  _______________  _______________
  [FUN] = LAYOUT_planck_mit(
    KC_ESC,          KC_RST,          _______,         _______,      _______,           KC_PSCR,         KC_NO,            KC_F7,           KC_F8,           KC_F9,           KC_F12,         _______,
    _______,         _______,         _______,         _______,      _______,           KC_SLCK,         KC_NO,            KC_F4,           KC_F5,           KC_F6,           KC_F11,          KC_LSFT,
    _______,         _______,         _______,         _______,      _______,           KC_PAUS,         KC_NO,            KC_F1,           KC_F2,           KC_F3,           KC_F10,          _______,
    _______,         _______,         _______,         _______,      _______,                       KC_SPC,             KC_ENT,          KC_DEL,         _______,         _______,         _______
  ),
//  layer 3
//  _______________  _______________  _______________  _______________  _______x_______  _______________  _______________  _______x_______  _______________  _______________  _______________  _______________
  [NSL] = LAYOUT_planck_mit(
    KC_ESC,          KC_GRV,          KC_LBRC,         KC_AMPR,         KC_ASTR,         KC_PIPE,         KC_RBRC,         KC_7,            KC_8,            KC_9,            KC_MINUS,      KC_BSPC,
    _______,         KC_NO,           KC_LCBR,         KC_DLR,          KC_PERC,         KC_CIRC,         KC_RCBR,         KC_4,            KC_5,            KC_6,            KC_EQL,        KC_LSFT,
    _______,         KC_NO,           KC_LPRN,         KC_EXLM,         KC_AT,           KC_HASH,         KC_RPRN,         KC_1,            KC_2,            KC_3,            KC_0,          _______,
    _______,         _______,         _______,         _______,         _______,                 KC_SPC,                  _______,          KC_DEL,          KC_DOT,         _______, _______
  ),
};
