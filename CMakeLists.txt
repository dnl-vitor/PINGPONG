cmake_minimum_required(VERSION 3.11)
project(pong)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(RAYLIB_VERSION 6.0)

find_package(raylib ${RAYLIB_VERSION} REQUIRED)
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
  include(FetchContent)
  FetchContent_Declare(
    raylib
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
  )
  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_MakeAvailable(raylib)
  endif()
endif()

add_executable(${PROJECT_NAME} main.cpp Ball.cpp Paddle.cpp)

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/assets"
    DESTINATION "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

 target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
