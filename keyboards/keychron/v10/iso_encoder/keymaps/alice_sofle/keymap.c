/* Copyright 2023 @ Keychron (https://www.keychron.com)
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

// clang-format off

enum layers{
    WIN_BASE,
    WIN_FN,
    BASE,
    NAV,
    NUMPAD,
};

#undef TAPPING_TERM
#define TAPPING_TERM 300
#define PERMISSIVE_HOLD

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

#define CTL_ESC RCTL_T(KC_ESC)

#define LSFT_A LSFT_T(KC_A)
#define LCTL_X LCTL_T(KC_X)
#define LALT_C LALT_T(KC_C)
#define LALTCO LALT_T(KC_COMM)
#define LCTLDO RCTL_T(KC_DOT)
#define LSFSCL LSFT_T(KC_SCLN)
#define LSFBSP LSFT_T(KC_BSPC)
#define RAL_SL RALT_T(KC_SLSH)
#define RALT_Z RALT_T(KC_Z)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [WIN_BASE] = LAYOUT_iso_90(
        KC_MUTE,  KC_ESC,   KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,  KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,   KC_F12,   KC_INS,          KC_DEL,

        _______,  KC_GRV,   KC_1,  KC_2,  KC_3,  KC_4,  KC_5,   KC_6,  KC_7,  KC_8,  KC_9,  KC_0,  KC_MINS,  KC_EQL,   KC_BSPC,         KC_PGUP,
        _______,  KC_TAB,   KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,   KC_Y,  KC_U,  KC_I,  KC_O,  KC_P,  KC_LBRC,  KC_RBRC,                   KC_PGDN,
        _______,  CTL_ESC,  KC_A,  KC_S,  KC_D,  KC_F,  KC_G,   KC_H,  KC_J,  KC_K,  KC_L,  KC_SCLN,  KC_QUOT,  KC_NUHS,  KC_ENT,          KC_HOME,
        _______,  KC_LSFT,  KC_NUBS,  KC_Z,  KC_X,  KC_C,  KC_V,   KC_B,  KC_B,  KC_N,  KC_M,  KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        _______,  KC_LCTL,  KC_LWIN,         KC_LALT,  KC_SPC,  MO(WIN_FN),  KC_SPC,          KC_RALT,                   KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_iso_90(
        RGB_TOG,  _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,   KC_VOLU,  _______,            _______,
        _______,  RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,   RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,   NK_TOGG,  _______,            _______,
        _______,  _______,  _______,  C(KC_W),  KC_WBAK,  KC_WFWD,  _______,                        KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   _______,  _______,   _______,                      _______,
        _______,  KC_CAPS,  C(KC_A),  C(KC_S),  S(KC_TAB), KC_TAB,  _______,                        KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______,   _______,  _______,            _______,
        _______,  _______,  KC_UNDO,  KC_CUT,   KC_COPY,  KC_PSTE,  _______,   _______,  _______,   MS_WHLL,  MS_WHLD,  MS_WHLU,  MS_WHLR,     _______,  _______,  _______,
        _______,  _______,  _______,            _______,  _______,  _______,                       _______,            KC_ESC,                        _______,  _______,  _______),


    [BASE] = LAYOUT_iso_90(
      KC_MUTE,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,

      KC_NO,          KC_ESC,   KC_1,  KC_2,  KC_3,  KC_4,  KC_5,                               KC_6,  KC_7,  KC_8,     KC_9,    KC_0,     KC_HOME,              KC_EQL,  KC_NO,  KC_NO,
      KC_NO,          KC_TAB,   KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,                               KC_Y,  KC_U,  KC_I,     KC_O,    KC_P,     KC_DEL,              KC_NO,  KC_NO,
      KC_NO,          CTL_ESC,  KC_A,  KC_S,  KC_D,  KC_F,  KC_G,                               KC_H,  KC_J,  KC_K,     KC_L,    KC_SCLN,  KC_END,                KC_NO,  KC_NO,  KC_NO,
      KC_NO,          KC_LSFT,  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  MO(NUMPAD),  MO(NUMPAD),     KC_N,  KC_M,  KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT,                KC_NO,
      KC_NO, KC_NO,             KC_LGUI,      KC_LALT,  KC_BSPC,  MO(NAV),      KC_SPC,  RALT_T(KC_ENT),                                            KC_NO,  KC_NO,  KC_NO
    ),

    [NAV] = LAYOUT_iso_90(
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,

        KC_NO,           _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                             KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   _______,      _______,  _______,  _______,
        KC_NO,           _______,  _______,  _______,  _______,  KC_F11,   KC_F12,                            KC_HOME,  KC_INS,   KC_DEL,   KC_END,   KC_PSCR,  KC_NO,        KC_NO,         KC_NO,
        KC_NO,           KC_CAPS,  KC_MPRV,  KC_MSTP,  KC_MPLY,  KC_MNXT,  _______,                           KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  KC_NO,        KC_NO,  KC_NO,  KC_NO,
        KC_NO,           _______,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,  _______,   _______,  _______,      _______,  KC_PGDN,  KC_PGUP,  KC_LALT,  _______,  KC_NO,        KC_NO,
        KC_NO,  KC_NO,             _______,              _______,  _______,  _______,                          _______,              _______,        _______,  _______,  _______
      ),

    [NUMPAD] = LAYOUT_iso_90(
      KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,

      KC_NO,            _______,  _______,  _______,  _______,  _______,  _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_NO,  KC_NO,
      KC_NO,            _______,  RGB_MOD,  RGB_HUI,  RGB_SAI,  RGB_VAI,  RGB_SPI,                                KC_PSLS,  KC_7,     KC_8,     KC_9,     KC_PPLS,            KC_NO,  KC_NO,  KC_NO,
      KC_NO,            _______,  RGB_RMOD, RGB_HUD,  RGB_SAD,  RGB_VAD,  RGB_SPD,                                KC_PAST,  KC_4,     KC_5,     KC_6,     KC_0,               KC_NO,  KC_NO,  KC_NO,  KC_NO,
      KC_NO,            _______,  _______,  _______,  _______,  _______,  _______,          _______,  _______,    KC_PMNS,  KC_1,     KC_2,     KC_3,     KC_PDOT,           KC_NO,  KC_NO,
      KC_NO,  KC_NO,            _______,               _______,  _______, _______,                                     KC_SPC,      KC_ENT,                                KC_NO,      KC_NO,      KC_NO    ),

};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [WIN_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [WIN_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [NAV]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [NUMPAD] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },

};
#endif // ENCODER_MAP_ENABLE
