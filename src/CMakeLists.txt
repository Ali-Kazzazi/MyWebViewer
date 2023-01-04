project(MyWebViewer LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets
    Gui WebEngineWidgets WebSockets)

set(PROJECT_SOURCES
        mainwindow.cpp
        DarkStyle.cpp
        serverinterface.cpp


        mainwindow.h
        DarkStyle.h
        serverinterface.h
)

set(PROJECT_RESOUECES
    MyWebViewer.qrc
)


add_library(MyWebViewerLib STATIC ${PROJECT_SOURCES})
add_library(MyWebViewerRes STATIC ${PROJECT_RESOUECES})

target_link_libraries(MyWebViewerLib PUBLIC Qt6::Core Qt6::Widgets Qt6::Gui
Qt6::WebEngineWidgets Qt6::WebSockets)


target_include_directories(MyWebViewerLib PUBLIC .)

