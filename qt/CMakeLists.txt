cmake_minimum_required(VERSION 3.23)
project(test_weather VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

include(FetchContent)
FetchContent_Declare(
    reflectcpp
    GIT_REPOSITORY https://github.com/getml/reflect-cpp.git
    GIT_TAG        v0.22.0
    GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(reflectcpp)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/reflectcpp_dummy_config)
file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/reflectcpp_dummy_config/reflectcpp-config.cmake
    "# Dummy reflectcpp-config.cmake\n"
    "# The target 'reflectcpp::reflectcpp' is already provided by FetchContent.\n"
    "if(NOT TARGET reflectcpp::reflectcpp)\n"
    "    message(FATAL_ERROR \"Target reflectcpp::reflectcpp not found!\")\n"
    "endif()\n"
)
set(reflectcpp_DIR ${CMAKE_CURRENT_BINARY_DIR}/reflectcpp_dummy_config CACHE PATH "Path to dummy reflectcpp config" FORCE)
set(SQLGEN_USE_VCPKG OFF CACHE BOOL "Use system packages instead of vcpkg" FORCE)
set(SQLGEN_SQLITE3 OFF CACHE BOOL "Disable SQLite3 support in sqlgen" FORCE)
FetchContent_Declare(
    sqlgen
    GIT_REPOSITORY https://github.com/getml/sqlgen.git
    GIT_TAG        v0.6.0
    GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(sqlgen)

add_executable(qt-widgets-cmake
    main.cpp
    form.cpp
    components/weather_info/weather_info.cpp
    components/day_weather/day_weather.cpp
    components/images/images.qrc
)

target_include_directories(qt-widgets-cmake PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/components/weather_info
    ${CMAKE_CURRENT_SOURCE_DIR}/components/day_weather
)

target_link_libraries(qt-widgets-cmake PRIVATE 
    Qt6::Widgets 
    sqlgen::sqlgen
)