
set(BINARY entity_test)

set(SOURCES
    main.cpp
    character_manager_test.cpp
    player_manager_test.cpp
)

add_executable(${BINARY} ${SOURCES})

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC
    gtest
    spdlog::spdlog
    entity_lib
)
