cmake_minimum_required(VERSION 3.20) # this is required in every cmakelists file.
project("Pointers Example") # this is required in every cmakelists file. This is just the project name.

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_COMPILER /usr/bin/gcc)

string(
    APPEND _opts
    "$<IF:$<CXX_COMPILER_ID:MSVC>,"
        "/W4;$<$<CONFIG:RELEASE>:/O2>,"
        "-Wall;-Wextra;-lm;-lc;-lgcc;-fdiagnostics-color=always;"
            "$<$<CONFIG:RELEASE>:-O3>"
            "$<$<CXX_COMPILER_ID:Clang>:-stdlib=libc++>"
    ">"
)

add_compile_options("${_opts}")

# get all the files source files
file(GLOB_RECURSE sources  src/*.c src/*.h)

# add the data to the target, so it becomes visible in some IDE
add_executable(exe_output ${sources})