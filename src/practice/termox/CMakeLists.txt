
set(BINARY TermOxPractice)

add_executable(${BINARY}
    main.cpp
)

target_include_directories(${BINARY}
  PRIVATE
)

target_link_libraries(${BINARY} PRIVATE
    spdlog::spdlog
    TermOx
)
