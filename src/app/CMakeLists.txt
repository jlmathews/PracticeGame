
set(BINARY ${CMAKE_PROJECT_NAME})

add_executable(${BINARY}_run
    main.cpp
)

target_include_directories(${BINARY}_run
  PUBLIC
    ${HIREDIS_HEADER}
    ${REDIS_PLUS_PLUS_HEADER}
)

target_link_libraries(${BINARY}_run PRIVATE
    ${BINARY}_lib
    spdlog::spdlog
    ${HIREDIS_LIB}
    ${REDIS_PLUS_PLUS_LIB}
)
