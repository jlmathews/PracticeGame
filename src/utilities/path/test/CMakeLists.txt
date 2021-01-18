
set(BINARY path_test)

set(SOURCES
    main.cpp
    path_test.cpp
)

add_executable(${BINARY} ${SOURCES})

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PRIVATE
    gtest
    spdlog::spdlog
    path_lib
)
