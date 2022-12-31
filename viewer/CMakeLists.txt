
set(CMAKE_AUTORCC ON)

add_executable(MyWebViewer main.cpp ../src/MyWebViewer.qrc)
#add_executable(MyWebViewer WIN32 main.cpp)
target_link_libraries(MyWebViewer MyWebViewerLib MyWebViewerRes)
