# Copyright (c) 2026 Donald Carr <d@chaos-reins.com>
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)
project(BetterEglfsPlatformThemePlugin LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui)
# Qt6::GuiPrivate is not always shipped as a CMake target (e.g. some Yocto SDKs).
# Private QPA headers are still required; we link GuiPrivate when present, else
# add the private include path that contains qpa/qplatformtheme.h.
find_package(Qt6 COMPONENTS GuiPrivate QUIET)

# Use add_library(MODULE) instead of qt_add_plugin(... TYPE ... SOURCES ...):
# Older Qt 6 CMake (e.g. some Yocto sysroots) does not treat TYPE / SOURCES as
# keywords and fails with "Cannot find source file: TYPE". A MODULE library is
# what Qt loads from platformthemes/; install path is set below.
set(CMAKE_AUTOMOC ON)

add_library(qbettereglfsplatformtheme MODULE
    bettereglfsplatformtheme.h
    bettereglfsplatformthemeplugin.h
    bettereglfsplatformthemeplugin.cpp
)

target_link_libraries(qbettereglfsplatformtheme
    PRIVATE
        Qt6::Core
        Qt6::Gui
)

if(TARGET Qt6::GuiPrivate)
    target_link_libraries(qbettereglfsplatformtheme PRIVATE Qt6::GuiPrivate)
elseif(DEFINED Qt6Gui_PRIVATE_INCLUDE_DIRS)
    target_include_directories(qbettereglfsplatformtheme PRIVATE
        ${Qt6Gui_PRIVATE_INCLUDE_DIRS})
else()
    # Typical sysroot layout: .../include/QtGui/<ver>/QtGui/private/qpa/...
    get_filename_component(_qt_prefix "${Qt6_DIR}/../../.." ABSOLUTE)
    file(GLOB _qt_gui_private_dirs "${_qt_prefix}/include/QtGui/*/QtGui/private")
    if(_qt_gui_private_dirs)
        list(SORT _qt_gui_private_dirs)
        list(GET _qt_gui_private_dirs -1 _qt_gui_private_dir)
        target_include_directories(qbettereglfsplatformtheme PRIVATE
            "${_qt_gui_private_dir}")
    else()
        message(FATAL_ERROR
            "Qt6::GuiPrivate target is missing and private QtGui headers were not "
            "found under ${_qt_prefix}/include/QtGui/*/QtGui/private. Install "
            "qtbase dev / private headers (or a Qt SDK that provides Qt6::GuiPrivate).")
    endif()
endif()

if(COMMAND qt_finalize_target)
    qt_finalize_target(qbettereglfsplatformtheme)
endif()

install(TARGETS qbettereglfsplatformtheme
    LIBRARY DESTINATION /opt/qt/plugins/platformthemes
    RUNTIME DESTINATION /opt/qt/plugins/platformthemes
)
