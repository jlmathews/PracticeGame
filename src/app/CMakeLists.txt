
set(BINARY ${CMAKE_PROJECT_NAME})

add_executable(${BINARY}_run
    main.cpp
)

target_link_libraries(${BINARY}_run PRIVATE
    ${BINARY}_lib
    spdlog::spdlog
)
