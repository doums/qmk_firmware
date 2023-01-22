// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

// `deip` keymap - Pierre_D
// This keymap is intended for use only with french layout (AZERTY)

#include QMK_KEYBOARD_H
#include <keymap_french.h>
#include <sendstring_french.h>

/* requires FR layout set (at OS level)
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
 * │Esc│ & │ é │ " │ ' │ ( │ - │ è │ _ │ ç │ ) │ * │ = │BkSpace│ ~ │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
 * │Tab  │ A │ Z │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │Pup│
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
 * │Ctrl  │ Q │ S │ D │ F │ G │ H │ J │ K │ L │ M │ $ │ Enter  │Pdo│
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
 * │Shift   │ W │ X │ C │ V │ B │ N │ , │ ; │ : │ ! │Shift │ ↑ │ ≡ │
 * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
 * │ ≡  │Gui │Alt │         Space          │Alt│Gui│CaL│ ← │ ↓ │ → │
 * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
 */

#define NO_MUSIC_MODE    // disable audio feature
#define LAYER_STATE_8BIT // use < 8 layers

enum layers {
    _BL = 0, // base
    _FL,     // F* keys
    _ML,     // macro
};

enum keycodes {
    LARW = SAFE_RANGE, // <-
    RARW,              // ->
    RARWD,             // =>
    RGB_RES,           // turn off RGB, but preserving Caps indicator
    FR_ECIR,           // ê
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BL] = LAYOUT_65_ansi(
        KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    FR_ASTR, KC_EQL,  KC_BSPC, KC_TILDE,
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
        KC_LCTL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGDN,
        KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   MO(_FL),
        OSL(_ML), KC_LGUI, KC_LALT,                            KC_SPC,           KC_RALT, KC_RGUI, KC_CAPS,          KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_FL] = LAYOUT_65_ansi(
        QK_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_GRV,
        RGB_RES, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, KC_PSCR, KC_SCRL, KC_PAUS, QK_BOOT, KC_HOME,
        _______, RGB_SPI, RGB_SPD, _______, _______, _______, _______, _______, _______, _______, _______, _______,          EE_CLR,  KC_END,
        KC_LSFT, _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______, _______,          KC_VOLU, KC_MUTE,
        KC_CAPS, _______, _______,                            _______,          _______, _______, _______,          KC_MPRV, KC_VOLD, KC_MNXT
    ),
    [_ML] = LAYOUT_65_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, FR_AGRV, _______, FR_ECIR, _______, _______, _______, FR_UGRV, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,    LARW, _______, _______,    RARW,   RARWD,          _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______,                            _______,          _______, _______, _______,          _______, _______, _______
    )
};

// override of modifier-key combinations
const key_override_t labk_ko = ko_make_basic(MOD_MASK_ALT, KC_M, FR_LABK);      // Alt + , = <
const key_override_t rabk_ko = ko_make_basic(MOD_MASK_ALT, KC_COMM, FR_RABK);   // Alt + ; = >
const key_override_t circ_ko = ko_make_basic(MOD_MASK_ALT, KC_LBRC, FR_CIRC);   // Alt + [ = ^ (dead)
const key_override_t diae_ko = ko_make_basic(MOD_MASK_ALT, KC_RBRC, FR_DIAE);   // Alt + ] = ¨ (dead)
const key_override_t agrv_ko = ko_make_basic(MOD_BIT(KC_RALT), KC_Q, FR_AGRV);  // RAlt + A = à
const key_override_t ugrv_ko = ko_make_basic(MOD_BIT(KC_RALT), KC_U, FR_UGRV);  // RAlt + U = ù
const key_override_t pipe_ko = ko_make_basic(MOD_MASK_SHIFT, KC_BSLS, FR_PIPE); // Shift + \ = |
const key_override_t lcbr_ko = ko_make_basic(MOD_MASK_SHIFT, KC_LBRC, FR_LCBR); // Shift + [ = {
const key_override_t rcbr_ko = ko_make_basic(MOD_MASK_SHIFT, KC_RBRC, FR_RCBR); // Shift + ] = }
const key_override_t sup2_ko = ko_make_basic(MOD_MASK_SHIFT, KC_TILD, FR_SUP2); // Shift + ~ = ²
const key_override_t dele_ko = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);  // Shift + backspace = delete
const key_override_t **key_overrides = (const key_override_t *[]){
    &labk_ko,
    &rabk_ko,
    &circ_ko,
    &diae_ko,
    &agrv_ko,
    &ugrv_ko,
    &pipe_ko,
    &lcbr_ko,
    &rcbr_ko,
    &sup2_ko,
    &dele_ko,
    NULL
};
// clang-format on

bool key_override_reg(uint16_t keycode, uint8_t mod_filter, keyrecord_t *record) {
    static bool key_registered;
    if (record->event.pressed) {
        if (!(get_mods() & mod_filter) && !(get_oneshot_mods() & mod_filter)) {
            register_code16(keycode);
            key_registered = true;
            return false;
        }
    } else if (key_registered) {
        unregister_code16(keycode);
        key_registered = false;
        return false;
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_BSLS:
            // keep us qwerty key `\`
            return key_override_reg(FR_BSLS, MOD_MASK_SHIFT, record);
        case KC_LBRC:
            // keep us qwerty key [
            return key_override_reg(FR_LBRC, MOD_MASK_SHIFT | MOD_MASK_ALT, record);
        case KC_RBRC:
            // keep us qwerty key ]
            return key_override_reg(FR_RBRC, MOD_MASK_SHIFT | MOD_MASK_ALT, record);
        case KC_QUOT:
            if (IS_LAYER_ON(_ML)) {
                return true;
            }
            // convert " to $
            return key_override_reg(FR_DLR, MOD_MASK_SHIFT, record);
        case KC_0:
            if (IS_LAYER_ON(_ML)) {
                return true;
            }
            // convert 0 to )
            return key_override_reg(FR_RPRN, MOD_MASK_SHIFT | MOD_MASK_ALT, record);
        case LARW:
            if (record->event.pressed) SEND_STRING("<-");
            return true;
        case RARW:
            if (record->event.pressed) SEND_STRING("->");
            return true;
        case RARWD:
            if (record->event.pressed) SEND_STRING("=>");
            return true;
        case RGB_RES:
            // turn off RGB
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv_noeeprom(HSV_OFF);
            return false;
        case FR_ECIR:
            // send ê
            if (record->event.pressed) SEND_STRING(SS_TAP(X_LBRC) "e");
            return true;
        default:
            return true; // Process all other keycodes normally
    }
}

// handle Caps Lock indicator
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(30, RGB_OFF); // turn off original Caps Lock slot
        rgb_matrix_set_color(63, RGB_PURPLE);
        rgb_matrix_set_color(64, RGB_PURPLE);
        rgb_matrix_set_color(65, RGB_PURPLE);
    }
    return false;
}

// turn off RGB lights, use only Caps Lock indicator
void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
}
