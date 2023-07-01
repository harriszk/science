cmake_minimum_required(VERSION 3.0.0)
project(Science VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-fdiagnostics-color=always -Wall -g")

include_directories(${PROJECT_SOURCE_DIR}/include/render/third-parties/include
    ${PROJECT_SOURCE_DIR}/include/physics/third-parties/include)
link_directories(${workspaceFolder}/include/render/third-parties/lib)

add_executable(Science 
    driver.cpp 
    src/render/Camera2D.cpp
    src/render/Circle.cpp
    src/render/Controller2D.cpp
    src/render/Display.cpp
    src/render/ElementBufferObject.cpp
    src/render/FirstPersonController.cpp
    src/render/FlyCamera.cpp
    src/render/glad.c
    src/render/Line.cpp
    src/render/Model.cpp
    src/render/Rectangle.cpp
    src/render/Renderer.cpp
    src/render/Scene.cpp
    src/render/Shader.cpp
    src/render/VertexArrayObject.cpp
    src/render/VertexBufferObject.cpp
    src/render/CoordinateSystem2D.cpp
    src/physics/PeriodicTable.cpp
    src/physics/Atom.cpp
    src/physics/Particle.cpp
    src/render/third-parties/imgui/imgui.cpp
    src/render/third-parties/imgui/imgui_widgets.cpp
    src/render/third-parties/imgui/imgui_tables.cpp
    src/render/third-parties/imgui/imgui_impl_opengl3.cpp
    src/render/third-parties/imgui/imgui_impl_glfw.cpp
    src/render/third-parties/imgui/imgui_draw.cpp
    src/render/third-parties/imgui/imgui_demo.cpp)

find_library(OPENGL_LIBRARY OpenGL)
find_library(COCOA_LIBRARY Cocoa)
find_library(IOKIT_LIBRARY IOKit)
find_library(COREVIDEO_LIBRARY CoreVideo)
find_library(COREFOUNDATION_LIBRARY CoreFoundation)

target_link_libraries(Science 
    ${OPENGL_LIBRARY} 
    ${COCOA_LIBRARY} 
    ${IOKIT_LIBRARY} 
    ${COREVIDEO_LIBRARY} 
    ${COREFOUNDATION_LIBRARY}
)

set_target_properties(Science PROPERTIES 
    LINK_FLAGS "-Wno-deprecated"
)

target_link_libraries(Science glfw)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
