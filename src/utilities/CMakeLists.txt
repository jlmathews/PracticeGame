
# generate a library from sources
add_library(utility_lib
    INTERFACE
)

target_include_directories(utility_lib
    INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

#target_link_libraries(utility_lib
#    PUBLIC
#    stduuid
#)

#add_subdirectory(test)
