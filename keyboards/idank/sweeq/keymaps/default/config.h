// Copyright 2023 Idan Kamara (@idank)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
// Set the mouse settings to a comfortable speed/accuracy trade-off,
// assuming a screen refresh rate of 60 Htz or higher
// The default is 50. This makes the mouse ~3 times faster and more accurate
#define MOUSEKEY_INTERVAL 16
// The default is 20. Since we made the mouse about 3 times faster with the previous setting,
// give it more time to accelerate to max speed to retain precise control over short distances.
#define MOUSEKEY_TIME_TO_MAX 40
// The default is 300. Let's try and make this as low as possible while keeping the cursor responsive
#define MOUSEKEY_DELAY 100
// It makes sense to use the same delay for the mouseweel
#define MOUSEKEY_WHEEL_DELAY 255
// The default is 100
#define MOUSEKEY_WHEEL_INTERVAL 255
// The default is 40
#define MOUSEKEY_WHEEL_TIME_TO_MAX 255

#define QUICK_TAP_TERM 0

// Tap dance
#define TAPPING_TERM 175
#define TAPPING_TERM_PER_KEY

// Auto Shift
// #define AUTO_SHIFT_TIMEOUT 175
#define NO_AUTO_SHIFT_ALPHA
