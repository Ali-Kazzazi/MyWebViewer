project(MyWebViewer LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

set(PROJECT_SOURCES
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

add_library(MyWebViewerLib STATIC ${PROJECT_SOURCES})

target_link_libraries(MyWebViewerLib PUBLIC Qt6::Core Qt6::Widgets )


target_include_directories(MyWebViewerLib PUBLIC .)

