// Copyright 2022 ssh (@snsten)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#define MATRIX_ROWS 8 // Rows are doubled-up.
#define MATRIX_COLS 5

#define VIAL_KEYBOARD_UID {0xFC, 0xF0, 0x00, 0x77, 0xB3, 0x1B, 0xE8, 0x7D}
#define VIAL_UNLOCK_COMBO_ROWS { 0, 0 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 1 }

#define MASTER_LEFT
#define SOFT_SERIAL_PIN D2

// Encoder support
#define ENCODERS_PAD_A { F5 }
#define ENCODERS_PAD_B { F4 }
#define ENCODERS_PAD_A_RIGHT { F4 }
#define ENCODERS_PAD_B_RIGHT { F5 }
#define ENCODER_RESOLUTIONS { 4 } //Left encoder seems to have double-output issue but right does not. This resolves that issue.


#define AUDIO_PIN B5

#ifdef POINTING_DEVICE_ENABLE
    #define POINTING_DEVICE_ROTATION_90
    #define CIRQUE_PINNACLE_DIAMETER_MM 35

    #define CIRQUE_PINNACLE_TAP_ENABLE
    // #define CIRQUE_PINNACLE_SECONDARY_TAP_ENABLE
    // #define POINTING_DEVICE_GESTURES_CURSOR_GLIDE_ENABLE
    // #define POINTING_DEVICE_GESTURES_SCROLL_ENABLE
#endif

#define OLED_DISPLAY_128X64
#define SPLIT_OLED_ENABLE

#ifdef AUDIO_ENABLE
    #define NO_MUSIC_MODE
#endif
