cmake_minimum_required(VERSION 3.20)
project(LeetCode_LLVM LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Compiler-Specific Configuration ---

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    message(STATUS "Configuring for Clang...")
    
    # 1. Try to find the LLVM prefix dynamically, fall back to brew default
    if(NOT LLVM_PREFIX)
        execute_process(COMMAND brew --prefix llvm OUTPUT_VARIABLE BREW_LLVM_PREFIX OUTPUT_STRIP_TRAILING_WHITESPACE ERROR_QUIET)
        if(BREW_LLVM_PREFIX)
            set(LLVM_PREFIX "${BREW_LLVM_PREFIX}" CACHE PATH "Path to LLVM installation")
        endif()
    endif()

    if(LLVM_PREFIX)
        message(STATUS "Using LLVM Prefix: ${LLVM_PREFIX}")
        set(LLVM_LIB_DIR "${LLVM_PREFIX}/lib")
        add_compile_options(-stdlib=libc++)
        add_link_options("-L${LLVM_LIB_DIR}" "-Wl,-rpath,${LLVM_LIB_DIR}" -stdlib=libc++)
        
        # 2. Check if LLD is available before trying to use it
        find_program(LLD_PATH NAMES ld.lld lld PATHS "${LLVM_PREFIX}/bin" "/home/linuxbrew/.linuxbrew/bin" NO_DEFAULT_PATH)
        if(LLD_PATH)
            message(STATUS "Found LLD: ${LLD_PATH}")
            add_link_options("-fuse-ld=lld")
        endif()
    endif()

    add_compile_options(-Wall -Wextra -Wpedantic -O3 -march=native)

elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    message(STATUS "Configuring for GCC...")
    add_compile_options(-Wall -Wextra -Wpedantic -O3 -march=native)
    # GCC uses libstdc++ by default and doesn't need special rpaths usually
endif()

# --- Target Generation ---

file(GLOB SOURCES CONFIGURE_DEPENDS "*.cpp")

foreach(source_file ${SOURCES})
    get_filename_component(exe_name ${source_file} NAME_WE)
    add_executable(${exe_name} ${source_file})
endforeach()
