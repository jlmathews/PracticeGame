
set(BINARY entity_test)

set(SOURCES
    main.cpp
    player_test.cpp
    unit_manager_test.cpp
)

add_executable(${BINARY} ${SOURCES})

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC
    gtest
    spdlog::spdlog
    entity_lib
    ${HIREDIS_LIB}
    ${REDIS_PLUS_PLUS_LIB}
)
