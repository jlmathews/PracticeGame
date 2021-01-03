
# generate a library from sources
add_library(attrib_lib
    STATIC
    attribute_list.cpp
    damage.cpp
    strength.cpp
)

target_include_directories(attrib_lib
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(attrib_lib
    PRIVATE
    spdlog::spdlog
)

add_subdirectory(test)
