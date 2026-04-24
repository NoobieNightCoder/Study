cmake_minimum_required(VERSION 3.16)

project(lab2 VERSION 0.1 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

add_library(core_logic STATIC
    BL/calculator.c
    BL/chartHandler.c
#    BL/errorHandler.c
    BL/memoryHandler.c
    BL/tableHandler.c
)

qt_add_executable(lab2
    main.cpp
    AppController/appController.cpp
    AppController/appController.h
    GUI/mainwindow.cpp
    GUI/mainwindow.h
    GUI/mainwindow.ui
    GUI/chartConstants.h
    GUI/chartGeometry.cpp
    GUI/chartGeometry.h
    GUI/chartViewHandler.cpp
    GUI/chartViewHandler.h
)

target_link_libraries(lab2 PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    core_logic)

set_target_properties(lab2 PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS lab2
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
