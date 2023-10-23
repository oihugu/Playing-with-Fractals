add_executable(${CMAKE_PROJECT_NAME} main.c)

add_subdirectory(IO)
add_subdirectory(logic)

target_link_libraries(${CMAKE_PROJECT_NAME}
    PRIVATE
    libmlx42.a
    dl
    glfw
    pthread
    m
    IO
    logic
)