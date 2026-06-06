cmake_minimum_required(VERSION 3.16)

project(lab3 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

qt_add_executable(lab3
    main.cpp

    # AppController
    AppController/AppController.cpp
    AppController/AppController.h
    AppController/Commands/IAppCommand.h
    AppController/Commands/EnterTokenCommand.cpp
    AppController/Commands/EnterTokenCommand.h
    AppController/Commands/ClearCommand.cpp
    AppController/Commands/ClearCommand.h
    AppController/Commands/DeleteCommand.cpp
    AppController/Commands/DeleteCommand.h
    AppController/Commands/CalculateCommand.cpp
    AppController/Commands/CalculateCommand.h
    AppController/Commands/MemoryClearCommand.cpp
    AppController/Commands/MemoryClearCommand.h
    AppController/Commands/MemoryRecallCommand.cpp
    AppController/Commands/MemoryRecallCommand.h
    AppController/Commands/MemoryPlusCommand.cpp
    AppController/Commands/MemoryPlusCommand.h
    AppController/Commands/MemoryMinusCommand.cpp
    AppController/Commands/MemoryMinusCommand.h
    AppController/Commands/FuncCommand.cpp
    AppController/Commands/FuncCommand.h

    # GUI
    GUI/mainwindow.cpp
    GUI/mainwindow.h
    GUI/mainwindow.ui

    GUI/DisplayValue.cpp
    GUI/DisplayValue.h

    # BL
    BL/CalculatorFacade.cpp
    BL/CalculatorFacade.h
    BL/CalculationContext.cpp
    BL/CalculationContext.h
    BL/Calculator.cpp
    BL/Calculator.h
    
    BL/Exceptions/ExceptionHandler.cpp
    BL/Exceptions/ExceptionHandler.h
    BL/Exceptions/AppException.cpp
    BL/Exceptions/AppException.h

    BL/Operations/IOperation.h
    BL/Operations/OperationRepository.cpp
    BL/Operations/OperationRepository.h
    BL/Operations/Operations.h
    BL/Operations/Plus.cpp
    BL/Operations/Plus.h
    BL/Operations/Minus.cpp
    BL/Operations/Minus.h
    BL/Operations/Multiplie.cpp
    BL/Operations/Multiplie.h
    BL/Operations/Division.cpp
    BL/Operations/Division.h
    BL/Operations/SquareRoot.cpp
    BL/Operations/SquareRoot.h
    BL/Operations/Sin.cpp
    BL/Operations/Sin.h
    BL/Operations/Cos.cpp
    BL/Operations/Cos.h
    BL/Operations/Tan.cpp
    BL/Operations/Tan.h
    BL/Operations/Cotan.cpp
    BL/Operations/Cotan.h
    
)

target_link_libraries(lab3 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(lab3 PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS lab3
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
