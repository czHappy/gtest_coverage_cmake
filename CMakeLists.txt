cmake_minimum_required(VERSION 3.10)
project(GTestCoverageExample)

set(CMAKE_CXX_STANDARD 14)

# === Enable coverage flags ===
option(COVERAGE "Enable coverage flags" ON)
if(COVERAGE)
    message(STATUS "Coverage enabled")
    add_compile_options(--coverage)
    link_libraries(--coverage)
endif()

# === Include header path ===
include_directories(${PROJECT_SOURCE_DIR}/include)

# === Source files ===
add_library(math src/math.cpp)

# === Find GTest ===
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# === Test target ===
add_executable(test_math test/test_math.cpp)
target_link_libraries(test_math math GTest::GTest GTest::Main pthread)

# === Enable testing and register the test ===
enable_testing()
add_test(NAME MathUnitTest COMMAND test_math)

# === Coverage target excluding test/ directory ===
add_custom_target(coverage
    COMMAND gcovr -r ${PROJECT_SOURCE_DIR} --exclude '${PROJECT_SOURCE_DIR}/test/*' --html --html-details -o coverage.html
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Generate coverage report excluding test/ directory"
)
