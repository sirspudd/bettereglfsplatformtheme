// Copyright (c) 2026 Donald Carr <d@chaos-reins.com>
// SPDX-License-Identifier: MIT

#pragma once

#include <qpa/qplatformtheme.h>

class BetterEglfsPlatformTheme final : public QPlatformTheme {
public:
    QVariant themeHint(ThemeHint hint) const override
    {
        switch (hint) {
        case FlickStartDistance:
            return 1;
        case FlickMaximumVelocity:
            return 32000;
        case FlickDeceleration:
            return 100;
        default:
            return QPlatformTheme::themeHint(hint);
        }
    }
};
