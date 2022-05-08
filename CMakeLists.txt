# Created by and for Qt Creator This file was created for editing the project sources only.
# You may attempt to use it for building too, by modifying this file here.

cmake_minimum_required(VERSION 3.5)
project(Proyecto02)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

include_directories(
    BMP
    build-Interfaz-Desktop-Debug
    Interfaz
)

set (SRCS
    BMP/cmake-build-debug/CMakeFiles/clion-environment.txt
    BMP/cmake-build-debug/CMakeFiles/clion-log.txt
    BMP/cmake-build-debug/CMakeFiles/cmake.check_cache
    BMP/cmake-build-debug/Testing/Temporary/LastTest.log
    BMP/cmake-build-debug/BMP
    BMP/cmake-build-debug/build.ninja
    BMP/cmake-build-debug/cmake_install.cmake
    BMP/cmake-build-debug/CMakeCache.txt
    BMP/cmake-build-debug/image.bmp
    BMP/BmpTutorial.cpp
    BMP/CMakeLists.txt
    BMP/Image.cpp
    BMP/Image.h
    build-Interfaz-Desktop-Debug/Interfaz
    build-Interfaz-Desktop-Debug/moc_mainwindow.cpp
    build-Interfaz-Desktop-Debug/moc_predefs.h
    build-Interfaz-Desktop-Debug/ui_mainwindow.h
    Interfaz/Interfaz.pro
    Interfaz/Interfaz_es_CR.ts
    Interfaz/main.cpp
    Interfaz/mainwindow.cpp
    Interfaz/mainwindow.h
    Interfaz/mainwindow.ui
    Interfaz/openglwidget.cpp
    Interfaz/openglwidget.h
)


add_executable(${CMAKE_PROJECT_NAME} ${SRCS})

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE Qt5::Core Qt5::Gui Qt5::Widgets)
