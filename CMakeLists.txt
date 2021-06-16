cmake_minimum_required(VERSION 3.1.0)

set(ProjName testwidget)

project(${ProjName} VERSION 1.0.0 LANGUAGES CXX)

# Only on Windows, set Prefix Path to MSVC as default for x86 Qt5Config.cmake
if (WIN32)
	set(CMAKE_PREFIX_PATH "C:\\Qt\\Qt5.12.11\\5.12.11\\msvc2017\\lib\\cmake\\Qt5")
endif()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_BINARY_DIR $ENV{TCPSOCKETGUI_BINARY_PATH})
message("${CMAKE_BINARY_DIR}")

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Network REQUIRED)
find_package(Qt5 COMPONENTS Concurrent REQUIRED)


# source files
set(source
 mythread.cpp
 myserver.cpp
 main.cpp
)

add_executable(${ProjName} ${source})

# Qt5 libraries
target_link_libraries(${ProjName} PUBLIC 
	Qt5::Widgets
	Qt5::Network
	Qt5::Concurrent
)

set_target_properties( ${ProjName}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
