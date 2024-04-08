project(GachaTest)

add_executable(GachaTest
        GachaTest.cpp
)

target_link_libraries(
        GachaTest
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(GachaTest)