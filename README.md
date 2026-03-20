# Qt 6 Platform Theme Plugin Example

This plugin overrides the following `QPlatformTheme::ThemeHint` values:

- `FlickStartDistance` -> `8`
- `FlickMaximumVelocity` -> `3200`
- `FlickDeceleration` -> `900`

## Build

The project uses `add_library(MODULE)` (not `qt_add_plugin` with `TYPE`/`SOURCES`) so it configures cleanly on **older Qt 6 CMake** toolchains (e.g. some Yocto sysroots) that mis-parse those keywords.

`Qt6::GuiPrivate` is optional: if your SDK does not provide that CMake target, the build adds the private QtGui include path (where `qpa/qplatformtheme.h` lives) automatically when headers are installed under `.../include/QtGui/*/QtGui/private`.

```bash
cmake -S . -B build
cmake --build build
```

## Install

Installs the plugin to `/opt/qt/plugins/platformthemes` (requires write permission; use `sudo` if needed):

```bash
sudo cmake --install build
```

## Run

Set the platform theme key to `bettereglfsplatformtheme` and make sure Qt can find the plugin (e.g. if Qt is under `/opt/qt`, plugins are usually found automatically):

```bash
QT_QPA_PLATFORMTHEME=bettereglfsplatformtheme QT_PLUGIN_PATH=/opt/qt/plugins ./your_qt_app
```

Enable plugin diagnostics if needed:

```bash
QT_DEBUG_PLUGINS=1 QT_QPA_PLATFORMTHEME=bettereglfsplatformtheme ./your_qt_app
```

## License

MIT License — see [LICENSE](LICENSE). Copyright (c) 2026 Donald Carr (d@chaos-reins.com).
