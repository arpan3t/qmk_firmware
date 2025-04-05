#include QMK_KEYBOARD_H

// # HOME ROW MODS #

// Left
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right
#define HOME_L LCTL_T(KC_L)
#define HOME_SCLN LSFT_T(KC_SCLN)

// # LAYER TAP DANCE MOD #
enum {
    TD_LYR_CAPS,
};

// # LAYERS #
enum layers{
  MAC_BASE,
  MAC_FN,
  WIN_BASE,
  WIN_2,
  WIN_FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[MAC_BASE] = LAYOUT_ansi_84(
     KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_SNAP,  KC_DEL,   RGB_MOD,
     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
     KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
     KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,    KC_END,
     KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 KC_RCMMD,MO(MAC_FN),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

[MAC_FN] = LAYOUT_ansi_84(
     KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_TRNS,  KC_TRNS,  RGB_TOG,
     KC_TRNS,  BT_HST1,  BT_HST2,  BT_HST3,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
     RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
     KC_TRNS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_TRNS,
     KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  BAT_LVL,  NK_TOGG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

/*    # 75% LAYOUT #
 *    ,________________________________________________________________________________________________________________________________________________,
 *    |------------------------------------------------------------------------------------------------------------------------------------------------|
 *    |        :        :        :        :        :        :        :        :        :        :        :        :        :        :        :         |
 *    |  ESC   :   F1   :   F2   :   F3   :   F4   :   F5   :   F6   :   F7   :   F8   :   F9   :   F10  :   F11  :   F12  :   PSCR :   DEL  : RGB MOD |
 *    |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
 *    |        :        :        :        :        :        :        :        :        :        :        :        :        :                 :         |
 *    |   ` ~  :   1    :   2    :   3    :   4    :   5    :   6    :   7    :   8    :   9    :   0    :   - _  :   = +  :          BSPC   :  PG UP  |
 *    |--------^-+------^-+-------^+-------^+-------^+-------^+-------^+-------^+-------^+-------^+-------^+-------^+-------^+---------------+---------|
 *    |          :        :        :        :        :        :        :        :        :        :        :        :        :               :         |
 *    |   TAB    :   Q    :   W    :   E    :   R    :   T    :   Y    :   U    :   I    :   O    :   P    :   [{   :   ]}   :         \ |   :  PG DN  |
 *    |----------^-+------^-+------^-+------^-+------^-+------^-+------^-+------^-+------^-+------^-+------^-+------^-+------^---------------+---------|
 *    |            :        :        :        :        :        :        :        :        :        :        :        :                      :         |
 *    |   CAPS     :   A    :   S    :   D    :   F    :   G    :   H    :   J    :   K    :   L    :   ; :  :   ' "  :              ENTER   :   HOME  |
 *    |------------^--+-----^--+-----^--+-----^--+-----^--+-----^--+-----^--+-----^--+-----^--+-----^--+-----^--+-----^-------------+--------+---------|
 *    |               :        :        :        :        :        :        :        :        :        :        :                   :        :         |
 *    |   SHIFT       :   Z    :   X    :   C    :   V    :   B    :   N    :   M    :  , <   :  . >   :  / ?   :        SHIFT      :   UP   :   END   |
 *    |---------+-----^---+----^----+---^--------^--------^--------^--------^--------^--------^-+------^-+------^-+--------+--------+--------+---------|
 *    |         :         :         :                                                           :        :        :        :        :        :         |
 *    |  CTRL   :   WIN   :   ALT   :                            SPACE                          :  ALT   :   FN   :  CTRL  :  LEFT  :  DOWN  :  RIGHT  |
 *    |---------^---------^---------^-----------------------------------------------------------^--------^--------^--------^--------^--------+---------|
 *    |________________________________________________________________________________________________________________________________________________|
*/

[WIN_BASE] = LAYOUT_ansi_84(
// |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
     KC_ESC,   KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_DEL,LGUI(KC_L),
// |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
     KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_MINS,  KC_EQL,         KC_BSPC,  KC_PGUP,
// |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
     KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_LBRC, KC_RBRC,         KC_BSLS,  KC_PGDN,
// |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
    TD(TD_LYR_CAPS), KC_A, HOME_S, HOME_D, HOME_F, KC_G,    KC_H,    KC_J,    KC_K,  HOME_L, HOME_SCLN, KC_QUOT,                   KC_ENT,  KC_HOME,
// |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
     KC_LSFT,         KC_Z,      KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,  KC_COMM,  KC_DOT,  KC_SLSH,        KC_RSFT,  KC_UP,     KC_END,
// |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
     KC_LCTL, KC_LGUI, KC_LALT,                     KC_SPC,                               KC_APP,  MO(WIN_FN),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT
// |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
),

[WIN_2] = LAYOUT_ansi_84(
// |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_MOD,
// |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
    _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F12, _______, _______,          _______, _______,
// |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, _______, KC_BSPS,  KC_DEL,          _______, _______,
// |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
    _______,  KC_END, _______, _______, _______, _______, KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, _______, _______,                   _______, _______,
// |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
// |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
    _______, _______, _______,                   _______,                                     _______, _______, _______, _______, _______, _______,
// |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
),

[WIN_FN] = LAYOUT_ansi_84(
     KC_TRNS,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_TRNS,  KC_TRNS,  RGB_TOG,
     KC_TRNS,  BT_HST1,  BT_HST2,  BT_HST3,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
     RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
     KC_TRNS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_TRNS,
     KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  BAT_LVL,  NK_TOGG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS)
};



// # LAYER TAP DANCE MOD #

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (get_highest_layer(layer_state) > 2) {
        uint8_t layer = get_highest_layer(layer_state);

        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index < led_max && index != NO_LED &&
                keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                    rgb_matrix_set_color(index, RGB_ORANGE);
                }
            }
        }
    }
    return false;
}

void cstm_layer_switch(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            layer_invert(WIN_2);
            break;
        case 2:
            register_code(KC_ESC);
            break;
        case 3:
            register_code(KC_CAPS);
            break;
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_LYR_CAPS] = ACTION_TAP_DANCE_FN(cstm_layer_switch),
};
