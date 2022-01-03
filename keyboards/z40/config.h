#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x8490
#define PRODUCT_ID      0x0004
#define DEVICE_VER      0x0001
#define PRODUCT         quarkeys_z40
#define DESCRIPTION     Keyboard

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 12

/* key matrix pins */
#define MATRIX_ROW_PINS { E6, B3, C7, C6 }
#define MATRIX_COL_PINS { F4, F5, F6, F7, B6, B5, B4, D7, D6, D0, B1, B0 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)


#define RGB_DI_PIN F1
#ifdef RGBLIGHT_ENABLE
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 47
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#endif

#ifdef RGB_MATRIX_ENABLE
#   define RGBLED_NUM 47
#   define DRIVER_LED_TOTAL RGBLED_NUM
#   define RGB_MATRIX_KEYPRESSES // reacts to keypresses
// #   define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (instead of keypresses)
// #   define RGB_DISABLE_AFTER_TIMEOUT 0 // number of ticks to wait until disabling effects
#   define RGB_DISABLE_WHEN_USB_SUSPENDED true // turn off effects when suspended
#   define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#   define RGB_MATRIX_LED_PROCESS_LIMIT (DRIVER_LED_TOTAL + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
#   define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
#   define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
#   define RGB_MATRIX_HUE_STEP 8
#   define RGB_MATRIX_SAT_STEP 8
#   define RGB_MATRIX_VAL_STEP 8
#   define RGB_MATRIX_SPD_STEP 10

/* Disable the animations you don't want/need.  You will need to disable a good number of these    *
 * because they take up a lot of space.  Disable until you can successfully compile your firmware. */
// #   define DISABLE_RGB_MATRIX_ALPHAS_MODS
// #   define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
// #   define DISABLE_RGB_MATRIX_BREATHING
#   define DISABLE_RGB_MATRIX_BAND_SAT
#   define DISABLE_RGB_MATRIX_BAND_VAL
#   define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#   define DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#   define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#   define DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL
// #   define DISABLE_RGB_MATRIX_CYCLE_ALL
// #   define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
// #   define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN
#   define DISABLE_RGB_MATRIX_CYCLE_OUT_IN
#   define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
// #   define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#   define DISABLE_RGB_MATRIX_DUAL_BEACON
#   define DISABLE_RGB_MATRIX_CYCLE_PINWHEEL
#   define DISABLE_RGB_MATRIX_CYCLE_SPIRAL
#   define DISABLE_RGB_MATRIX_RAINBOW_BEACON
#   define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
// #   define DISABLE_RGB_MATRIX_RAINDROPS
// #   define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
// #   define DISABLE_RGB_MATRIX_TYPING_HEATMAP
// #   define DISABLE_RGB_MATRIX_DIGITAL_RAIN
// #   define DISABLE_RGB_MATRIX_SOLID_REACTIVE
// #   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
// #   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
// #   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
// #   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
// #   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
// #   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
// #   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
// #   define DISABLE_RGB_MATRIX_SPLASH
// #   define DISABLE_RGB_MATRIX_MULTISPLASH
// #   define DISABLE_RGB_MATRIX_SOLID_SPLASH
// #   define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif


#endif
