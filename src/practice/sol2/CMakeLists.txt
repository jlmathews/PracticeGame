
set(BINARY sol2_practice)

message("*** Lua include: ${LUA_INCLUDE_DIR}")
message("*** Lua library: ${LUA_LIBRARIES}")

# Copy function modified from https://stackoverflow.com/questions/697560/how-to-copy-directory-from-source-tree-to-binary-tree
macro(copy_lua_files srcDir destDir)
    message(STATUS "Configuring directory ${destDir}")
    make_directory(${destDir})

    file(GLOB templateFiles RELATIVE ${srcDir} ${srcDir}/*.lua)
    foreach(templateFile ${templateFiles})
        set(srcTemplatePath ${srcDir}/${templateFile})
        if(NOT IS_DIRECTORY ${srcTemplatePath})
            message(STATUS "Configuring file ${templateFile}")
            configure_file(
                    ${srcTemplatePath}
                    ${destDir}/${templateFile}
                    @ONLY)
        endif(NOT IS_DIRECTORY ${srcTemplatePath})
    endforeach(templateFile)
endmacro(configure_files)

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
)
