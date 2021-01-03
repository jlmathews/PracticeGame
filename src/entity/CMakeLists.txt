
# generate a library from sources
add_library(entity_lib
    STATIC
    beast.cpp
    player.cpp
    unit.cpp
    unit_manager.cpp
)

target_include_directories(entity_lib
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${HIREDIS_HEADER}
    ${REDIS_PLUS_PLUS_HEADER}
)

target_link_libraries(entity_lib
    PUBLIC
    spdlog::spdlog
    movement_lib
    ${HIREDIS_LIB}
    ${REDIS_PLUS_PLUS_LIB}
    utility_lib
    stduuid
)

add_subdirectory(test)
