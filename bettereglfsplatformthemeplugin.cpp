// Copyright (c) 2026 Donald Carr <d@chaos-reins.com>
// SPDX-License-Identifier: MIT

#include "bettereglfsplatformthemeplugin.h"

#include "bettereglfsplatformtheme.h"

QPlatformTheme *BetterEglfsPlatformThemePlugin::create(const QString &key, const QStringList &)
{
    if (key.compare(QStringLiteral("bettereglfsplatformtheme"), Qt::CaseInsensitive) == 0) {
        qDebug() << "bettereglfsplatformtheme is in play";
        return new BetterEglfsPlatformTheme;
    }
    return nullptr;
}
