
set(BINARY storage_test)
set(RESULTS ${BINARY}_results.xml)

set(SOURCES
    main.cpp
    redis_adapter_test.cpp
    storage_interface_test.cpp
)

add_executable(${BINARY} ${SOURCES})

add_test(NAME ${BINARY} COMMAND ${BINARY} --gtest_output=xml:${RESULTS})

target_link_libraries(${BINARY} PRIVATE
    gtest
    spdlog::spdlog
    storage_lib
)
