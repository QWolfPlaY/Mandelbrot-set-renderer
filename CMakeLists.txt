cmake_minimum_required(VERSION 3.23)
project(Mandelbrot_set_renderer)

set(CMAKE_CXX_STANDARD 20)

link_directories(lib/SDL2/x86_64-w64-mingw32/lib)
include_directories(lib/SDL2/x86_64-w64-mingw32/include)

#add_executable(${PROJECT_NAME} ${MY_SOURCES})
#target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2)

add_executable(Mandelbrot_set_renderer
        src/main.cpp)
