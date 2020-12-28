
set(BINARY attrib_lib_test)

set(SOURCES main.cpp damage_test.cpp)

add_executable(${BINARY} ${SOURCES})

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC
    gtest
    spdlog::spdlog
    attrib_lib
)
