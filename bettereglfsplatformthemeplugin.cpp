// Copyright (c) 2026 Donald Carr <d@chaos-reins.com>
// SPDX-License-Identifier: MIT

#include "bettereglfsplatformthemeplugin.h"

#include "bettereglfsplatformtheme.h"

QPlatformTheme *BetterEglfsPlatformThemePlugin::create(const QString &key, const QStringList &)
{
    if (key.compare(QStringLiteral("bettereglfsplatformtheme"), Qt::CaseInsensitive) == 0) {
        qCDebug(betterEGLFSPlaformTheme) << "bettereglfsplatformtheme is in play";
        return new BetterEglfsPlatformTheme;
    }
    return nullptr;
}

Q_LOGGING_CATEGORY(betterEGLFSPlaformTheme, "qt.qpa.bettereglfsplatformtheme")
