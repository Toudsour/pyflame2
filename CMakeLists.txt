cmake_minimum_required(VERSION 3.16)

project(pyflame2)

set(PYFLAME2_SOURCE
        src/aslr.cc
        src/frame.cc
        src/frob37.cc
        src/namespace.cc
        src/posix.cc
        src/prober.cc
        src/ptrace.cc
        src/pyflame.cc
        src/pyfrob.cc
        src/symbol.cc
        src/thread.cc)

set(PYFLAME2_HEADER
        src/aslr.h
        src/exc.h
        src/frame.h
        src/namespace.h
        src/posix.h
        src/prober.h
        src/ptrace.h
        src/pyfrob.h
        src/setns.h
        src/symbol.h
        src/thread.h src/frob37.cc)

find_package (Python3 3.7 EXACT COMPONENTS Interpreter Development)

if(Python3_FOUND)
    message("Found python, version: ${Python3_VERSION}, include dir ${Python3_INCLUDE_DIRS}")
endif()

add_executable(pyflame2 ${PYFLAME2_SOURCE} ${PYFLAME2_HEADER})
target_include_directories(pyflame2 PRIVATE ${Python3_INCLUDE_DIRS})
add_compile_definitions(pyflame2 PRIVATE ENABLE_PY37 PYFLAME_VERSION_STR=pyflame2 PYFLAME_PY_VERSION=37 USE_ELF64 ENABLE_THREADS)

