
set(BINARY sol2_practice)

message("*** Lua include: ${LUA_INCLUDE_DIR}")
message("*** Lua library: ${LUA_LIBRARIES}")

copy_lua_files(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

add_executable(${BINARY}
    main.cpp
)

target_include_directories(${BINARY}
  PRIVATE
  ${LUA_INCLUDE_DIR}
)

target_link_libraries(${BINARY} PRIVATE
    spdlog::spdlog
    ${LUA_LIBRARIES}
    path_lib
    sol2::sol2
    LuaWrapper
)
