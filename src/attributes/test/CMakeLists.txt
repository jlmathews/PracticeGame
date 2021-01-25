
set(BINARY attrib_lib_test)
set(RESULTS ${BINARY}_results.xml)

set(SOURCES
    main.cpp
    attribute_list_test.cpp
    damage_test.cpp
)

add_executable(${BINARY} ${SOURCES})

add_test(NAME ${BINARY} COMMAND ${BINARY} --gtest_output=xml:${RESULTS})

target_link_libraries(${BINARY} PUBLIC
    gtest
    spdlog::spdlog
    attrib_lib
)
