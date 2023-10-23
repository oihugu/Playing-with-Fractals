add_library(logic "")

target_sources(logic
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/complex.c
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/complex.h
  )

  target_sources(logic
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/fractal.c
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/fractal.h
  )

  target_sources(logic
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/init_data.c
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/init_data.h
  )

  target_sources(logic
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/mandelbrot.c
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/mandelbrot.h
  )

target_include_directories(logic
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )