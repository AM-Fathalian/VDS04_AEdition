cmake_minimum_required(VERSION 3.14)
project(VDSProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- 1. Automatic GTest Download (Modern Method) ---
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
# Prevent GTest from overriding your compiler settings (Windows/Linux safety)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# --- 2. Include Directories ---
# This allows you to include "Manager.h" anywhere
include_directories(src)

# --- 3. Define Sources ---
set(SOURCE_FILES
        src/Manager.cpp
        src/Manager.h
        src/ManagerInterface.h
)

# --- 4. Define Executables ---

# A. The Main App (For your manual checks)
add_executable(VDSProject_Run src/main.cpp ${SOURCE_FILES})

# B. The Test App (For CI and GTest)
enable_testing()
add_executable(VDSProject_Test src/test/main_test.cpp ${SOURCE_FILES})

# Link GTest to the test executable
target_link_libraries(VDSProject_Test gtest_main)

# Register tests so CLion sees them
include(GoogleTest)
gtest_discover_tests(VDSProject_Test)