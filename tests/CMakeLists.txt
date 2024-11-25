cmake_minimum_required(VERSION 3.14)
project(all-tests.exe)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(all-tests.exe
  src/test_vector2.cpp
  src/test_robot.cpp
)

target_link_libraries(
  all-tests.exe
  walle-lib
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(all-tests.exe)


