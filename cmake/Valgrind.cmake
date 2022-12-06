# Step 1: Try to find valgrind

find_program(VALGRIND "valgrind")

if(NOT VALGRIND)
    message(WARNING "valgrind was not found on your \$\{PATH\}")
else()
    message(INFO " valgrind located")
    set(CMAKE_MEMORYCHECK_COMMAND "${VALGRIND}")
endif()