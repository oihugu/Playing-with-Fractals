add_library(IO "")

target_sources(IO
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/colors.c
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/colors.h
  )

  target_sources(IO
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/controls.c
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/controls.h
  )

  target_sources(IO
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/error.c
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/error.h
  )

target_include_directories(IO
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )