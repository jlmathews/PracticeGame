
# generate a library from sources
add_library(storage_lib
    STATIC
    redis_adapter.cpp
)

target_include_directories(storage_lib
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${HIREDIS_HEADER}
    ${REDIS_PLUS_PLUS_HEADER}
)

target_link_libraries(storage_lib
    PUBLIC
    spdlog::spdlog
    ${HIREDIS_LIB}
    ${REDIS_PLUS_PLUS_LIB}
)

add_subdirectory(test)
