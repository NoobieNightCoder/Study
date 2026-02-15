cmake_minimum_required(VERSION 3.16)

project(Aboba VERSION 0.1 LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(Qt6_DIR "C:/Qt/6.10.2/mingw_64/lib/cmake/Qt6")

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

add_library(core_logic STATIC
    logic/logic.c
)

qt_add_executable(Aboba
    ui/main.cpp
    ui/app_controller.cpp
    ui/app_controller.h
    ui/mainwindow.cpp
    ui/mainwindow.h
    ui/mainwindow.ui
)

target_link_libraries(Aboba PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    core_logic
)

set_target_properties(Aboba PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Aboba
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
