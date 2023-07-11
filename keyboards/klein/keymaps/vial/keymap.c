#include QMK_KEYBOARD_H

enum klein_keymap_layers {
    L_BASE = 0,
    L_NAV,
    L_NUM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐      [4]   [5]    ┌───┐
      *           │ 1 ├───┐           ┌───┤ 8 │
      *           └───┤ 2 ├───┐   ┌───┤ 7 ├───┘
      *               └───┤ 3 │   │ 6 ├───┘
      *                   └───┘   └───┘
      */
  [0] = LAYOUT_split_3x5_4(
  // ╭─────────────────────────────────────────────────────────────╮                      ╭────────────────────────────────────────────────────────────────╮
      KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,                        KC_Y, KC_U,         KC_I,         KC_O,         KC_P,
  // ├─────────────────────────────────────────────────────────────┤                      ├────────────────────────────────────────────────────────────────┤
      LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,                        KC_H, RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_QUOT),
  // ├─────────────────────────────────────────────────────────────┤                      ├────────────────────────────────────────────────────────────────┤
      KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,                        KC_N, KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
  // ╰─────────────────────────────────────────────────────────────╯                      ╰────────────────────────────────────────────────────────────────╯
      KC_ESC, LT(L_NAV, KC_SPC), LT(L_NUM, KC_TAB), QK_BOOT,                             QK_BOOT, KC_ENT, LT(L_NUM, KC_BSPC), KC_DEL
  // ╰───────────────────────────────────────────────────────────────────╯              ╰─────────────────────────────────────────────────────────────────╯
  ),
  
    [1] = LAYOUT_split_3x5_4(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_CAPS, KC_NO,   KC_NO,   KC_NO,   KC_NO,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
         KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_INS,  KC_HOME, KC_PGUP, KC_PGDN, KC_NO,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                      KC_NO, KC_NO, KC_NO, QK_BOOT,    QK_BOOT, KC_ENT, KC_BSPC, KC_DEL
  //                 ╰─────────────────────────────╯ ╰────────────────────────────────╯
  ),
  
   [2] = LAYOUT_split_3x5_4(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
         KC_LBRC,   KC_7, KC_8, KC_9,   KC_RBRC,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
         KC_SCLN,   KC_4, KC_5, KC_6,   KC_EQL,       KC_NO,   KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
         KC_GRV,    KC_1, KC_2, KC_3,   KC_BSLS,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                   KC_DOT, KC_0, KC_MINS, QK_BOOT,    QK_BOOT, KC_ENT, KC_BSPC, KC_DEL
  //              ╰────────────────────────────────╯ ╰────────────────────────────────╯
  )

};

#if defined(ENCODER_MAP_ENABLE)

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [1] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [2] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  }
};
#endif


#ifdef OLED_ENABLE

    oled_rotation_t oled_init_user(oled_rotation_t rotation) {
        if (!is_keyboard_master()) {
            return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
        }

        return rotation;
    }

    static void render_my_logo(void) {
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
        };

        oled_write_P(qmk_logo, false);
    }

    bool oled_task_user(void) { 
      if (is_keyboard_master()) {
            render_my_logo();   
        } else {
            render_my_logo();  
        }
        return false;
    }
#endif

