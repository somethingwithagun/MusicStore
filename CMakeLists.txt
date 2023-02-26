cmake_minimum_required(VERSION 3.16)

project(Rent VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_FLAGS -g)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

add_executable(Rent
    mainwindow.ui
    database.cpp
    regWindow.cpp
    logWindow.cpp
    currentAccount.cpp
    refillBalanceWindow.cpp
    mainwindow.cpp
    main.cpp
)
target_link_libraries(Rent PRIVATE
    Qt6::Widgets)

set_target_properties(Rent PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)