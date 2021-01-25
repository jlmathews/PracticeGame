
# generate a library from sources
add_library(entity_lib
    STATIC
    beast.cpp
    character_manager.cpp
    unit.cpp
    player_manager.cpp
    unit_manager.cpp
)

target_include_directories(entity_lib
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(entity_lib
    PUBLIC
    spdlog::spdlog
    movement_lib
    storage_lib
    utility_lib
    stduuid
)

add_subdirectory(test)
