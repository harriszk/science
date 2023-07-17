cmake_minimum_required(VERSION 3.0.0)
project(science VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

SET(PROJECT_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/..")

INCLUDE_DIRECTORIES(
  ${PROJECT_ROOT}
)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-fdiagnostics-color=always -Wall -g")

include_directories(${PROJECT_SOURCE_DIR}/third-parties/include
    ${PROJECT_SOURCE_DIR}/include/physics/third-parties/include)

add_executable(science 
    driver.cc
    src/application.cc
    src/logger.cc
    src/events/key_event.cc
    src/events/key_pressed_event.cc
    src/events/key_released_event.cc
    src/events/key_typed_event.cc
)

target_include_directories(science PRIVATE "${CMAKE_SOURCE_DIR}/include")

# Add include directory for imgui
target_include_directories(science PRIVATE "${CMAKE_SOURCE_DIR}/third-parties/include")

find_library(OPENGL_LIBRARY OpenGL)
find_library(COCOA_LIBRARY Cocoa)
find_library(IOKIT_LIBRARY IOKit)
find_library(COREVIDEO_LIBRARY CoreVideo)
find_library(COREFOUNDATION_LIBRARY CoreFoundation)

target_link_libraries(science 
    ${OPENGL_LIBRARY} 
    ${COCOA_LIBRARY} 
    ${IOKIT_LIBRARY} 
    ${COREVIDEO_LIBRARY} 
    ${COREFOUNDATION_LIBRARY}
)

set_target_properties(science PROPERTIES 
    LINK_FLAGS "-Wno-deprecated"
)

target_link_libraries(science glfw)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)