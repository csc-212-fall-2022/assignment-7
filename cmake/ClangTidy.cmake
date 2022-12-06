find_program(CLANG_TIDY_EXE "clang-tidy")

if(NOT CLANG_TIDY_EXE)
    message(WARNING "clang-tidy is not available!")
else()
    message(INFO " clang-tidy located")
    set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE}")
endif()