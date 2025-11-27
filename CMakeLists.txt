#cmake_minimum_required(VERSION 3.10)
#project(VDSProject CXX C)
#set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -fPIC -std=c++17 ${LLVM_CXX_FLAGS} ")
#
#
## Download and unpack googletest at configure time
#configure_file(CMakeLists.txt.in ${CMAKE_SOURCE_DIR}/gtest/googletest-download/CMakeLists.txt)
#execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
#        RESULT_VARIABLE result
#        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/gtest/googletest-download )
#if(result)
#    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
#endif()
#execute_process(COMMAND ${CMAKE_COMMAND} --build .
#        RESULT_VARIABLE result
#        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/gtest/googletest-download )
#if(result)
#    message(FATAL_ERROR "Build step for googletest failed: ${result}")
#endif()
#
## Add googletest directly to our build. This defines
## the gtest and gtest_main targets.
#add_subdirectory(${CMAKE_SOURCE_DIR}/gtest/googletest-src
#        ${CMAKE_SOURCE_DIR}/gtest/googletest-build
#        EXCLUDE_FROM_ALL)
#
## The gtest/gtest_main targets carry header search path
## dependencies automatically when using CMake 2.8.11 or
## later. Otherwise we have to add them here ourselves.
#if (CMAKE_VERSION VERSION_LESS 2.8.11)
#    include_directories("${gtest_SOURCE_DIR}/include")
#endif()
#
##Include dirs
#include_directories(${CMAKE_SOURCE_DIR}/lib)
#link_directories(${CMAKE_SOURCE_DIR}/lib)
#
#include_directories(${CMAKE_SOURCE_DIR}/src)
#link_directories(${CMAKE_SOURCE_DIR}/src)
#
#include_directories(${CMAKE_SOURCE_DIR}/src/test/)
#link_directories(${CMAKE_SOURCE_DIR}/src/test/)
#
#include_directories(${CMAKE_SOURCE_DIR}/src/bench/)
#link_directories(${CMAKE_SOURCE_DIR}/src/bench/)
#
#include_directories(${CMAKE_SOURCE_DIR}/src/verify/)
#link_directories(${CMAKE_SOURCE_DIR}/src/verify/)
#
#
#add_subdirectory(src)
#
## Example snippet for src/CMakeLists.txt
#add_executable(run_tests src/test/main_test.cpp) #
#target_link_libraries(run_tests GTest::gtest_main Manager) # Link against GTest and your BDD Manager library
#
#add_executable(VDSProject src/main.cpp)
#target_link_libraries(VDSProject Manager)
################################################################################3
#
#cmake_minimum_required(VERSION 3.14)
#project(VDSProject)
#
## 1. Set C++ Standard
#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#
## 2. Setup Google Test (Automatically downloads it)
#include(FetchContent)
#FetchContent_Declare(
#        googletest
#        URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
#)
## For Windows: Prevent overriding the parent project's compiler/linker settings
#set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
#FetchContent_MakeAvailable(googletest)
#
## 3. Include Directories
#include_directories(src)
#
## 4. Define Source Files (The Manager Class)
## Ensure your Manager.cpp and Manager.h are inside a 'src' folder
#set(SOURCE_FILES
#        src/Manager.cpp
#        src/Manager.h
#        src/ManagerInterface.h
#)
#
## 5. Create the Main Executable (For your own manual testing)
#add_executable(VDSProject_Run src/main.cpp ${SOURCE_FILES})
#
## 6. Create the Test Executable (For GTest)
#enable_testing()
#
## Create a test file called src/test/main_test.cpp
#add_executable(VDSProject_Test
#        src/test/main_test.cpp
#        ${SOURCE_FILES}
#)
#
## Link GTest to the test executable
#target_link_libraries(VDSProject_Test gtest_main)
#
## Register the test so it appears in CLion's "Run Tests" menu
#include(GoogleTest)
#gtest_discover_tests(VDSProject_Test)

################################################################################3
#Second Approach 27/11/2025
cmake_minimum_required(VERSION 3.14)
project(VDSProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- 1. GTest Setup (Requirement #3) ---
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# --- 2. Source Files ---
include_directories(src)

# Define the core library sources
set(SOURCE_FILES
        src/Manager.cpp
        src/Manager.h
        src/ManagerInterface.h
)

# --- 3. Executables ---

# Main Run (For your manual testing)
add_executable(VDSProject_Run src/main.cpp ${SOURCE_FILES})

# Test Run (For GTest & CI)
enable_testing()
add_executable(VDSProject_Test src/test/main_test.cpp ${SOURCE_FILES})
target_link_libraries(VDSProject_Test gtest_main)

# Register tests
include(GoogleTest)
gtest_discover_tests(VDSProject_Test)

