
set(BINARY ${CMAKE_PROJECT_NAME}App)
set(PROJECT_LIB ${CMAKE_PROJECT_NAME}_lib)

add_executable(${BINARY}
    main.cpp
)

target_include_directories(${BINARY}
  PUBLIC
    ${HIREDIS_HEADER}
    ${REDIS_PLUS_PLUS_HEADER}
)

target_link_libraries(${BINARY} PRIVATE
    ${PROJECT_LIB}
    spdlog::spdlog
    ${HIREDIS_LIB}
    ${REDIS_PLUS_PLUS_LIB}
)
