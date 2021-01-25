
set(BINARY ${CMAKE_PROJECT_NAME}_test)
set(PROJECT_LIB ${CMAKE_PROJECT_NAME}_lib)
set(RESULTS ${BINARY}_results.xml)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

set(SOURCES ${TEST_SOURCES})

add_executable(${BINARY} ${TEST_SOURCES})

add_test(NAME ${BINARY} COMMAND ${BINARY} --gtest_output=xml:${RESULTS})

target_link_libraries(${BINARY} PUBLIC
    ${PROJECT_LIB}
    gtest
    spdlog::spdlog)
