
set(BINARY LuaWrapperTest)

set(SOURCES
    main.cpp
    lua_wrapper_test.cpp
)

copy_lua_files(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

add_executable(${BINARY} ${SOURCES})

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PRIVATE
    gtest
    spdlog::spdlog
    LuaWrapper
    sol2::sol2
)
