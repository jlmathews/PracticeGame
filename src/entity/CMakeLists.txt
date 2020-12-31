
# generate a library from sources
add_library(entity_lib
    STATIC
    beast.cpp
    player.cpp
    unit.cpp
)

target_include_directories(entity_lib
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(entity_lib
    PUBLIC
    spdlog::spdlog
    movement_lib
)

add_subdirectory(test)
