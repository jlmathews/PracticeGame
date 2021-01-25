
set(BINARY ${CMAKE_PROJECT_NAME}_test)
set(PROJECT_LIB ${CMAKE_PROJECT_NAME}_lib)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

set(SOURCES ${TEST_SOURCES})

add_executable(${BINARY} ${TEST_SOURCES})

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC
    ${PROJECT_LIB}
    gtest
    spdlog::spdlog)
