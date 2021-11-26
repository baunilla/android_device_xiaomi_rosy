/*
 * Copyright (C) 2019 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "Lights.h"

#include <fstream>

namespace aidl {
namespace android {
namespace hardware {
namespace light {

#define LEDS            "/sys/class/leds/"
#define LCD_LED         LEDS "lcd-backlight/"
#define WHITE_LED       LEDS "red/"
#define BLINK           "blink"
#define BRIGHTNESS      "brightness"

#define LCD_BRIGHTNESS_SCALE    (4095 / 0xFF)

#define AutoHwLight(light) {.id = (int)light, .type = light, .ordinal = 0}

const static std::vector<HwLight> kAvailableLights = {
    AutoHwLight(LightType::BACKLIGHT),
    AutoHwLight(LightType::BATTERY),
    AutoHwLight(LightType::NOTIFICATIONS),
    AutoHwLight(LightType::ATTENTION)
};

void Lights::write(const std::string &path, uint32_t value) {
    std::ofstream file(path);

    if (file.is_open()) {
        file << std::to_string(value);
    }
}

uint32_t Lights::RgbaToBrightness(uint32_t color) {
    uint32_t alpha = (color >> 24) & 0xFF;
    uint32_t red = (color >> 16) & 0xFF;
    uint32_t green = (color >> 8) & 0xFF;
    uint32_t blue = color & 0xFF;

    if (alpha != 0xFF) {
        red = red * alpha / 0xFF;
        green = green * alpha / 0xFF;
        blue = blue * alpha / 0xFF;
    }
    return (77 * red + 150 * green + 29 * blue) >> 8;
}

void Lights::setNotificationLight(const HwLightState& state) {
    if (state.flashMode == FlashMode::TIMED) {
        write(WHITE_LED BLINK, (state.flashOnMs != 0 && state.flashOffMs != 0));
    } else {
        write(WHITE_LED BRIGHTNESS, RgbaToBrightness(state.color));
    }
}

ndk::ScopedAStatus Lights::setLightState(int id, const HwLightState& state) {
    switch (id) {
        case (int)LightType::BACKLIGHT:
            write(LCD_LED BRIGHTNESS, RgbaToBrightness(state.color) * LCD_BRIGHTNESS_SCALE);
            break;
        case (int)LightType::BATTERY:
        case (int)LightType::NOTIFICATIONS:
        case (int)LightType::ATTENTION:
            setNotificationLight(state);
            break;
        default:
            return ndk::ScopedAStatus::fromExceptionCode(EX_UNSUPPORTED_OPERATION);
            break;
    }
    return ndk::ScopedAStatus::ok();
}

ndk::ScopedAStatus Lights::getLights(std::vector<HwLight>* lights) {
    for (auto i = kAvailableLights.begin(); i != kAvailableLights.end(); i++) {
        lights->push_back(*i);
    }
    return ndk::ScopedAStatus::ok();
}

}  // namespace light
}  // namespace hardware
}  // namespace android
}  // namespace aidl
