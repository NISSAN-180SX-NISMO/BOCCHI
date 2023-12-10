cmake_minimum_required(VERSION 3.26)

# Найти интерпретатор Python
find_program(PYTHON_EXECUTABLE python PATHS ${CMAKE_SOURCE_DIR}/venv/bin)

if(NOT PYTHON_EXECUTABLE)
    message(FATAL_ERROR "Python interpreter not found.")
endif()

# Вызываем скрипт ComponentScanner.py перед началом компиляции
add_custom_target(scan_components
        COMMAND ${PYTHON_EXECUTABLE} "${CMAKE_CURRENT_SOURCE_DIR}/Bocchi/ComponentScanner/ComponentScan.py"
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Bocchi/ComponentScanner
)

# Добавьте scan_components как зависимость для вашей цели компиляции

project(Bocchi)

set(CMAKE_CXX_STANDARD 17)

add_executable(Bocchi main.cpp
        Bocchi/BocchiCore/ComponentRegistry/ComponentRegistry.h
        Bocchi/BocchiCore/ComponentRegistry/ComponentRegistryException.h
        Bocchi/BocchiCore/Context_class/Context.cpp
        Bocchi/BocchiCore/Context_class/Context.h
        Bocchi/BocchiApplication/MenuCase.h
        Bocchi/BocchiApplication/BocchiApplication_class/BocchiApplication.h
        Bocchi/BocchiApplication/BocchiApplication_class/BocchiApplication.cpp
        MainMenuCase.h
        Bocchi/BocchiCore/ComponentRegistry/Object.h
        Bocchi/BocchiApplication/IncludeComponents.h
        TestCases/TestCase1.h
        TestCases/TestCase2.h
        Bocchi/EventSystem/Event.h
        Bocchi/EventSystem/ConsoleHandler.h
        Bocchi/EventSystem/ObservedInterface.h
        Bocchi/EventSystem/ObserverInterface.h
        Bocchi/BocchiApplication/BocchiApplicationStateUpdater.h
        Bocchi/BocchiApplication/MenuState.h
        Bocchi/Utils/Carousel.h
        TestCases/TestCase3.h
        TestCases/TestCase2_1.h
        TestCases/TestCase2_2.h)
add_dependencies(Bocchi scan_components)
