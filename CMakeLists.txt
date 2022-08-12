cmake_minimum_required(VERSION 3.0.0)
project(TestProject VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(GroupJobResultAggregator main.cpp)

add_executable(GroupJobResultAggregatorTest main.cpp)

add_test(
NAME GroupJobResultAggregatorTest
COMMAND $<TARGET_FILE:GroupJobResultAggregatorTest>
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
