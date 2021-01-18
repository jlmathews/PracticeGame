
# generate a library from sources
add_library(path_lib
    STATIC
    path.cpp
)

target_include_directories(path_lib
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(path_lib
    PRIVATE
    spdlog::spdlog
)

add_subdirectory(test)
