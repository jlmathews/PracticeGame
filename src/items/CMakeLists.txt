
# generate a library from sources
add_library(items_lib
    STATIC
    armor.cpp
    item.cpp
    weapon.cpp
)

target_include_directories(items_lib
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(items_lib
    PUBLIC
    spdlog::spdlog
    attrib_lib
)
