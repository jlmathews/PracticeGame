
set(BINARY LuaWrapper)

message("*** Lua include: ${LUA_INCLUDE_DIR}")
message("*** Lua library: ${LUA_LIBRARIES}")

# generate a library from sources
add_library(${BINARY}
    STATIC
    lua_wrapper.cpp
)

target_include_directories(${BINARY}
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${LUA_INCLUDE_DIR}
)

target_link_libraries(${BINARY} PRIVATE
    spdlog::spdlog
    ${LUA_LIBRARIES}
    path_lib
    sol2::sol2
)

add_subdirectory(test)
