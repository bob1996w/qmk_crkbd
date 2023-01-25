/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2022 @bob1996w

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "print.h"
#include "version.h"

// Home Row Mod
#define HM_A    MT(MOD_LCTL, KC_A)
#define HM_S    MT(MOD_LALT, KC_S)
#define HM_D    MT(MOD_LGUI, KC_D)
#define HM_F    MT(MOD_LSFT, KC_F)
#define HM_J    MT(MOD_RSFT, KC_J)
#define HM_K    MT(MOD_RGUI, KC_K)
#define HM_L    MT(MOD_RALT, KC_L)
#define HM_SCLN MT(MOD_RCTL, KC_SCLN)
#define LSFTCAP MT(MOD_LSFT, KC_CAPS)
#define MAC_SCR G(S(C(KC_4)))

enum Layer {
    BASE = 0,
    RAISE,
    LOWER,
    ADJUST,
    GAME,
    EXTRA
};

enum Keycodes {
    KC_DVER = SAFE_RANGE, // for version and other debug things
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_ESC,    HM_A,    HM_S,    HM_D,    HM_F,    KC_G,                         KC_H,    HM_J,    HM_K,    HM_L, HM_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LSFTCAP,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LSFT, FN_MO23,  KC_SPC,     KC_ENT, FN_MO13, KC_BSPC
                                      //`--------------------------'  `--------------------------'
  ),

  [RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_VOLU, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END, KC_VOLD, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, _______,  KC_SPC,     KC_ENT, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_QUOT,   KC_LT,   KC_GT, KC_DQUO,  KC_GRV,                      KC_AMPR, XXXXXXX, KC_LBRC, KC_RBRC, KC_PERC,DF(GAME),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MAC_SCR, KC_EXLM, KC_MINS, KC_PLUS,  KC_EQL, KC_HASH,                      KC_PIPE, KC_COLN, KC_LPRN, KC_RPRN, KC_QUES, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_PSCR, KC_CIRC, KC_SLSH, KC_ASTR, KC_BSLS,  KC_DLR,                      KC_TILD, KC_UNDS, KC_LCBR, KC_RCBR,   KC_AT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_DVER, _______,  KC_SPC,    CW_TOGG, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_BTN1, KC_MS_U, KC_BTN2, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_BTN3, KC_BTN2, KC_BTN1, XXXXXXX,                      XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [GAME] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX,    KC_Q,    KC_W,    KC_E,    KC_R,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX,    KC_A,    KC_S,    KC_D,    KC_F,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX,    KC_Z,    KC_X,    KC_C,    KC_V,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX,MO(EXTRA), XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [EXTRA] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,DF(BASE),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE
#include <stdio.h>

bool isCapsOn = false;

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master()) {
    return OLED_ROTATION_270;   // flips the display 90 degrees
  }
  else {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

char layer_str[26] = {};

void oled_draw_layer(uint8_t layer) {
    static const char PROGMEM STATE_ICON[][16] = {
        {0x20, 0x80, 0x81, 0x82, 0x83, 0x20, 0xa0, 0xa1, 0xa2, 0xa3, 0x20, 0xc0, 0xc1, 0xc2, 0xc3, 0},
        {0x20, 0x84, 0x85, 0x86, 0x87, 0x20, 0xa4, 0xa5, 0xa6, 0xa7, 0x20, 0xc4, 0xc5, 0xc6, 0xc7, 0},
        {0x20, 0x88, 0x89, 0x8a, 0x8b, 0x20, 0xa8, 0xa9, 0xaa, 0xab, 0x20, 0xc8, 0xc9, 0xca, 0xcb, 0},
        {0x20, 0x8c, 0x8d, 0x8e, 0x8f, 0x20, 0xac, 0xad, 0xae, 0xaf, 0x20, 0xcc, 0xcd, 0xce, 0xcf, 0},
        {0x20, 0x90, 0x91, 0x92, 0x93, 0x20, 0xb0, 0xb1, 0xb2, 0xb3, 0x20, 0xd0, 0xd1, 0xd2, 0xd3, 0},
        {0x20, 0x94, 0x95, 0x96, 0x97, 0x20, 0xb4, 0xb5, 0xb6, 0xb7, 0x20, 0xd4, 0xd5, 0xd6, 0xd7, 0}
    };
    oled_set_cursor(0, 0);
    if (layer < 6) {
        oled_write_P(STATE_ICON[layer], false);
    }
}

void oled_render_layer_state(void) {
    uint8_t layer = get_highest_layer(layer_state | default_layer_state);
    oled_draw_layer(layer);
    // oled_set_cursor(0, 0);
    // switch (layer) {
    //     case BASE:
    //         oled_write_P(PSTR("Base "), false);
    //         break;
    //     case LOWER:
    //         oled_write_P(PSTR("Lower"), false);
    //         break;
    //     case RAISE:
    //         oled_write_P(PSTR("Raise"), false);
    //         break;
    //     case ADJUST:
    //         oled_write_P(PSTR("Adj  "), false);
    //         break;
    //     case GAME:
    //         oled_write_P(PSTR("Game "), false);
    //         break;
    //     case EXTRA:
    //         oled_write_P(PSTR("Extra"), false);
    //         break;
    // }
    // oled_set_cursor(0, 1);
    // snprintf(layer_str, sizeof(layer_str), "%5d", layer);
    // oled_write(layer_str, false);
}

char keylog_str[26] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  // char name = ' ';
  //   if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
  //       (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  // if (keycode < 60) {
  //   name = code_to_name[keycode];
  // }

  // update keylog
  // snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d:%c",
  //          record->event.key.row, record->event.key.col,
  //          keycode, name);
    snprintf(keylog_str, sizeof(keylog_str), "key:\n%dx%d",
             record->event.key.row, record->event.key.col);
}

void oled_render_keylog(void) {
    oled_set_cursor(0, 4);
    oled_write(keylog_str, false);
}

void oled_render_led(void) {
    led_t state = host_keyboard_led_state();
    oled_set_cursor(0, 13);
    if (state.caps_lock) {
        static const char PROGMEM caps_led[] = { 0xbc, 0xbd, 0 };
        oled_write_P(caps_led, false);
    } else {
        oled_write_P(PSTR("  "), false);
    }
    oled_set_cursor(0, 14);
    if (state.num_lock) {
        static const char PROGMEM num_led[] = { 0xbe, 0xbf, 0 };
        oled_write_P(num_led, false);
    } else {
        oled_write_P(PSTR("  "), false);
    }
    oled_set_cursor(0, 15);
    if (state.scroll_lock) {
        static const char PROGMEM scroll_led[] = { 0xdc, 0xdd, 0 };
        oled_write_P(scroll_led, false);
    } else {
        oled_write_P(PSTR("  "), false);
    }
}

void oled_render_caps_word(void) {
    oled_set_cursor(0, 12);
    if (is_caps_word_on()) {
        static const char PROGMEM capswd_logo[] = { 0x9c, 0x9d, 0x9e, 0x9f, 0 };
        oled_write_P(capswd_logo, false);
    } else {
        oled_write_P(PSTR("    "), false);
    }
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
        oled_render_led();
        oled_render_caps_word();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        set_keylog(keycode, record);
    }

    switch (keycode) {
        case KC_DVER:
            if (record->event.pressed) {
                SEND_STRING("crkbd:bob1996w " __DATE__ " " __TIME__ "@qmk" QMK_VERSION);
            }
            return false;
    }
    return true;
}
#endif // OLED_ENABLE
