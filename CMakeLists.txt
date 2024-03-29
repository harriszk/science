cmake_minimum_required(VERSION 3.10)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "cmake")

set(ProjectName "science")
set(ProjectNamespace "SCIENCE")

project("${ProjectName}" VERSION 0.1.0)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-fdiagnostics-color=always -Wall -g")

include_directories(${PROJECT_SOURCE_DIR}/dependencies)
include_directories(${PROJECT_SOURCE_DIR}/dependencies/imgui)

# =========================================================
# gtest

include(FetchContent)
FetchContent_Declare(
  googletest
  URL
  https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set_property(TARGET gmock PROPERTY FOLDER "gtest")
set_property(TARGET gmock_main PROPERTY FOLDER "gtest")
set_property(TARGET gtest PROPERTY FOLDER "gtest")
set_property(TARGET gtest_main PROPERTY FOLDER "gtest")

# =========================================================

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/third-parties/include)

add_library("${ProjectName}" STATIC
  # Source files
  src/logger.cc
  src/utility.cc
  src/display.cc
  src/application.cc
  src/event_manager.cc
  src/imgui_system.cc
  src/render_manager.cc

  src/render/shader.cc
  src/render/frame_buffer_object.cc

  src/events/keyboard_event.cc
  src/events/key_pressed_event.cc
  src/events/key_released_event.cc
  src/events/key_typed_event.cc
  src/events/mouse_event.cc
  src/events/mouse_moved_event.cc
  src/events/mouse_scrolled_event.cc
  src/events/mouse_button_event.cc
  src/events/mouse_button_pressed_event.cc
  src/events/mouse_button_released_event.cc
  src/events/window_event.cc
  src/events/window_closed_event.cc
  src/events/window_resized_event.cc
  src/events/window_moved_event.cc
  src/events/window_focus_changed_event.cc
  src/events/frame_buffer_changed_event.cc

  src/editor/menu_bar_panel.cc
  src/editor/scene_panel.cc
  src/editor/asset_panel.cc

  # Third party source files
  third-parties/include/glad/glad.c
  third-parties/include/imgui/imgui.cpp
  third-parties/include/imgui/imgui_widgets.cpp
  third-parties/include/imgui/imgui_tables.cpp
  third-parties/include/imgui/imgui_impl_opengl3.cpp
  third-parties/include/imgui/imgui_impl_glfw.cpp
  third-parties/include/imgui/imgui_demo.cpp
  third-parties/include/imgui/imgui_draw.cpp
)

target_compile_definitions("${ProjectName}" PRIVATE 
  PROJECT_NAMESPACE=${ProjectNamespace},
  SHADER_BASE_DIRECTORY="${CMAKE_SOURCE_DIR}/assets/shaders/"
)

add_executable("${ProjectName}-main"
  # Source files
  driver.cc

  # Header files
)

target_include_directories("${ProjectName}-main" PRIVATE
  ${CMAKE_SOURCE_DIR}/include
  ${CMAKE_SOURCE_DIR}/third-parties/include
)

find_library(OPENGL_LIBRARY OpenGL)
find_library(COCOA_LIBRARY Cocoa)
find_library(IOKIT_LIBRARY IOKit)
find_library(COREVIDEO_LIBRARY CoreVideo)
find_library(COREFOUNDATION_LIBRARY CoreFoundation)

target_link_libraries("${ProjectName}-main" 
  ${OPENGL_LIBRARY} 
  ${COCOA_LIBRARY} 
  ${IOKIT_LIBRARY} 
  ${COREVIDEO_LIBRARY} 
  ${COREFOUNDATION_LIBRARY}
)

target_link_libraries("${ProjectName}-main" 
  "${ProjectName}"
  glfw
)

# gtest

enable_testing()

add_executable("${ProjectName}-test"
  # Source files
  test/sanity_test.cc
  test/events_test.cc
  test/event_manager_test.cc
  test/display_test.cc

  # Header files
)

target_link_libraries("${ProjectName}-test"
  gtest_main
  "${ProjectName}"
  glfw
)

include(GoogleTest)
gtest_discover_tests("${ProjectName}-test")