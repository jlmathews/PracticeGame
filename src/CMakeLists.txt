
set(BINARY ${CMAKE_PROJECT_NAME})

option(USE_LIBRARY "Compile sources into a library" OFF)
message(STATUS "Compile sources into a library? ${USE_LIBRARY}")

add_subdirectory(app)
add_subdirectory(attributes)
add_subdirectory(entity)
add_subdirectory(items)
add_subdirectory(movement)
add_subdirectory(utilities)

set(SOURCES "")

add_library(${BINARY}_lib STATIC ${SOURCES})

target_include_directories(${BINARY}_lib
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${HIREDIS_HEADER}
    ${REDIS_PLUS_PLUS_HEADER}
)

message("C++ compiler flags: ${flags}")
target_compile_options(${BINARY}_lib
    PRIVATE
    ${flags}
)

target_link_libraries(${BINARY}_lib PUBLIC
    spdlog::spdlog
    entity_lib
    items_lib
    attrib_lib
    movement_lib
    ${HIREDIS_LIB}
    ${REDIS_PLUS_PLUS_LIB}
)
