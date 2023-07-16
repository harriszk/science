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
    third-parties/include/imgui/imgui.cpp
    third-parties/include/imgui/imgui_widgets.cpp
    third-parties/include/imgui/imgui_tables.cpp
    third-parties/include/imgui/imgui_impl_opengl3.cpp
    third-parties/include/imgui/imgui_impl_glfw.cpp
    third-parties/include/imgui/imgui_draw.cpp
    third-parties/include/imgui/imgui_demo.cpp
    src/application.cc
    src/render/camera_2d.cc
    src/render/circle.cc
    src/render/controller_2d.cc
    src/render/display.cc
    src/render/element_buffer_object.cc
    src/render/first_person_controller.cc
    src/render/fly_camera.cc
    src/render/glad.c
    src/render/line.cc
    src/render/model.cc
    src/render/rectangle.cc
    src/render/renderer.cc
    src/render/scene.cc
    src/render/shader.cc
    src/render/vertex_array_object.cc
    src/render/vertex_buffer_object.cc
    src/render/coordinate_system_2d.cc
    src/physics/periodic_table.cc
    src/physics/atom.cc
    src/physics/particle.cc
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
