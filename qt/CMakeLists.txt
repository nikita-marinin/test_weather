cmake_minimum_required(VERSION 3.5)
project(test_weather VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)


add_executable(qt-widgets-cmake main.cpp form.cpp)

target_link_libraries(qt-widgets-cmake PRIVATE Qt6::Widgets)