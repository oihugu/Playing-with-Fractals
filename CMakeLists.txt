cmake_minimum_required(VERSION 3.10)

project(mlx42_project)

set(CMAKE_CXX_STANDARD 17)

add_executable(mlx42 main.c)

target_link_libraries(mlx42
    libmlx42.a
    dl
    glfw
    pthread
    m
)
