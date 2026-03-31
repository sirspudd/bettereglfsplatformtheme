// Copyright (c) 2026 Donald Carr <d@chaos-reins.com>
// SPDX-License-Identifier: MIT

#pragma once

#include <QObject>
#include <qpa/qplatformthemeplugin.h>

#include <QtCore/QLoggingCategory>

Q_DECLARE_LOGGING_CATEGORY(betterEGLFSPlaformTheme)

class BetterEglfsPlatformThemePlugin final : public QPlatformThemePlugin {
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QPlatformThemeFactoryInterface_iid FILE "bettereglfsplatformtheme.json")

public:
    QPlatformTheme *create(const QString &key, const QStringList &params) override;
};
