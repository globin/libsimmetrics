SET (CMAKE_C_COMPILER "/usr/bin/clang")
include_directories("${libsimmetrics_SOURCE_DIR}/include")

add_executable(exampleProgram exampleProgram.c)
target_link_libraries(exampleProgram simmetrics m)
