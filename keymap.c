/* Copyright 2026 Alfred Hodler
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

enum layers {
    _ALPHA,
    _NAV,
    _SYM,
    _NUM,
    _UTIL,
};

// KVM input change macros
enum custom_keycodes {
  KVM_1 = SAFE_RANGE,
  KVM_2,
  KVM_3,
  KVM_4
};

// Home row mods
#define HR_A MT(MOD_LGUI, KC_A)
#define HR_S MT(MOD_LALT, KC_S)
#define HR_D MT(MOD_LCTL, KC_D)
#define HR_F MT(MOD_LSFT, KC_F)
#define HR_J MT(MOD_RSFT, KC_J)
#define HR_K MT(MOD_RCTL, KC_K)
#define HR_L MT(MOD_RALT, KC_L)
#define HR_q MT(MOD_RGUI, KC_QUOTE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_ALPHA] = LAYOUT_split_3x5_3(
        KC_Q,      KC_W,       KC_E,       KC_R,       KC_T,      /*|*/     KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,
        HR_A,      HR_S,       HR_D,       HR_F,       KC_G,      /*|*/     KC_H,       HR_J,       HR_K,       HR_L,       HR_q,
        KC_Z,      KC_X,       KC_C,       KC_V,       KC_B,      /*|*/     KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,
        KC_ESCAPE, LT(_NAV, KC_SPACE), KC_TAB,                    /*|*/                 KC_BSPC,    LT(_SYM, KC_ENTER),     MO(_UTIL)
    ),
    [_NAV] = LAYOUT_split_3x5_3(
        XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,   /*|*/     XXXXXXX,    KC_HOME,    KC_PGUP,    XXXXXXX,    KC_PSCR,
        KC_LGUI,   KC_LALT,    KC_LCTL,    KC_LSFT,    XXXXXXX,   /*|*/     KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    CW_TOGG,
        XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,   /*|*/     XXXXXXX,    KC_END,     KC_PGDN,    XXXXXXX,    KC_CAPS,
        _______,   _______,    _______,                           /*|*/                             KC_DELETE,  MO(_NUM),   _______
    ),
    [_SYM] = LAYOUT_split_3x5_3(
        KC_QUES,   KC_COLN,    KC_LPRN,    KC_RPRN,    KC_PIPE,   /*|*/     KC_ASTR,    KC_LABK,    KC_RABK,    KC_CIRC,    _______,
        KC_EXLM,   KC_UNDS,    KC_LCBR,    KC_RCBR,    KC_DQUO,   /*|*/     KC_PLUS,    KC_MINUS,   KC_EQUAL,   KC_GRAVE,   KC_SCLN,
        KC_AT,     KC_DLR,     KC_LBRC,    KC_RBRC,    KC_HASH,   /*|*/     KC_PERC,    KC_AMPR,    _______,    KC_TILD,    KC_BSLS,
        _______,   MO(_NUM),   _______,                           /*|*/                             _______,    _______,    _______
    ),
    [_NUM] = LAYOUT_split_3x5_3(
        KC_F1,     KC_F2,     KC_F3,       KC_F4,      KC_F5,     /*|*/     KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,
        KC_1,      KC_2,      KC_3,        KC_4,       KC_5,      /*|*/     KC_6,       KC_7,       KC_8,       KC_9,       KC_0,
        KC_F11,    KC_F12,    XXXXXXX,     XXXXXXX,    XXXXXXX,   /*|*/     XXXXXXX,    KC_END,     KC_COMM,    KC_DOT,     XXXXXXX,
        _______, _______, _______,                                /*|*/                             _______,    _______,    _______
    ),
    [_UTIL] = LAYOUT_split_3x5_3(
        QK_BOOT,   XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,   /*|*/     XXXXXXX,    KC_PWR,     KC_SLEP,    KC_WAKE,    KC_MUTE,
        XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,   /*|*/     XXXXXXX,    KVM_1,      KVM_2,      KVM_3,      KVM_4,
        XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,   /*|*/     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
        XXXXXXX,   XXXXXXX,    XXXXXXX,                                                             XXXXXXX,    XXXXXXX,    _______
    ),
};

// Chordal hold handedness (exemptions)
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT_split_3x5_3(
  'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R',
  'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R',
  'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R',
            '*', '*', '*', '*', '*', '*');

// Macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case KVM_1:
                SEND_STRING(SS_TAP(X_LEFT_CTRL)SS_DELAY(100)  SS_TAP(X_LEFT_CTRL)SS_DELAY(100)  SS_TAP(X_1));
                return false;
            case KVM_2:
                SEND_STRING(SS_TAP(X_LEFT_CTRL)SS_DELAY(100)  SS_TAP(X_LEFT_CTRL)SS_DELAY(100)  SS_TAP(X_2));
                return false;
            case KVM_3:
                SEND_STRING(SS_TAP(X_LEFT_CTRL)SS_DELAY(100)  SS_TAP(X_LEFT_CTRL)SS_DELAY(100)  SS_TAP(X_3));
                return false;
            case KVM_4:
                SEND_STRING(SS_TAP(X_LEFT_CTRL)SS_DELAY(100)  SS_TAP(X_LEFT_CTRL)SS_DELAY(100)  SS_TAP(X_4));
                return false;
        }
    }
    return true;
};
