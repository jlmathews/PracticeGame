
# generate a library from sources
add_library(movement_lib
    STATIC
    position.cpp
)

target_include_directories(movement_lib
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(movement_lib
    PUBLIC
    spdlog::spdlog
)
