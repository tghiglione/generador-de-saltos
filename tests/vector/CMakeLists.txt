project(VectorTest)

add_executable(VectorTest
        VectorTest.cpp
)

target_link_libraries(
        VectorTest
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(VectorTest)