include(CMakePrintHelpers)
cmake_minimum_required(VERSION 3.16)
project(WiTCHHUNT VERSION 1.0.0 LANGUAGES CXX)
add_executable(${PROJECT_NAME} MACOSX_BUNDLE)

file(GLOB_RECURSE RESOURCE_FILES content/*)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_EXTENSIONS ON)
set_property(TARGET ${PROJECT_NAME} PROPERTY OUTPUT_NAME WiTCHHUNT)

set(PROJECT_INCLUDE_DIRS
        src
        )

set(PROJECT_SOURCE_FILES
        src/rom_character_table.cpp
        src/engine.cpp
        src/witchhunt.cpp
        src/main.cpp
        )

set_target_properties(${PROJECT_NAME} PROPERTIES
        RESOURCE "${RESOURCE_FILES}"
        MACOSX_BUNDLE_BUNDLE_NAME "WiTCHHUNT"
        MACOSX_BUNDLE_BUNDLE_VERSION "1.0.0"
        MACOSX_BUNDLE_COPYRIGHT "Copyright CCPS Solutions"
        MACOSX_BUNDLE_GUI_IDENTIFIER com.ccpssolutions.witchhunt)

set_source_files_properties(${RESOURCE_FILES} PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")

find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2_image sdl2_ttf sdl2_mixer)

target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_INCLUDE_DIRS} ${PROJECT_INCLUDE_DIRS})
target_sources(${PROJECT_NAME} PRIVATE ${RESOURCE_FILES} ${PROJECT_SOURCE_FILES})
target_link_directories(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARY_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARIES})
