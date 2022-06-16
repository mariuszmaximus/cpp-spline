cmake_minimum_required(VERSION 3.0.0)
project(qtsample VERSION 0.1.0)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)



find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
    message(STATUS "QNANOPAINTER QT VERSION=${QT_VERSION_MAJOR}")
if(QT_VERSION_MAJOR EQUAL  6)
    find_package(Qt6 REQUIRED COMPONENTS Widgets OpenGL Quick OpenGLWidgets)
    set(QNANOPAINTER_QT_LIBS  Qt6::Widgets Qt6::OpenGL Qt6::Quick Qt6::OpenGLWidgets)
else()
    find_package(Qt5 REQUIRED COMPONENTS Widgets OpenGL Quick )
    set(QNANOPAINTER_QT_LIBS  Qt5::Widgets Qt5::OpenGL Qt5::Quick)
endif()

if(QT_VERSION_MAJOR EQUAL  5)
    find_package(Qt5 COMPONENTS Core)
    find_package(Qt5 COMPONENTS Gui)
    find_package(Qt5 COMPONENTS Charts)
endif()

if(QT_VERSION_MAJOR EQUAL  6)
    find_package(Qt6 COMPONENTS Core)
    find_package(Qt6 COMPONENTS Gui)
    find_package(Qt6 COMPONENTS Charts)
endif()

add_executable(qtsample main.cpp)

target_link_libraries(qtsample PUBLIC
    Qt::Charts
    Qt::Core
    Qt::Gui
    cpp-spline
)