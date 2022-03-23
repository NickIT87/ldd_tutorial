#include <iostream>
#include <gtest/gtest.h>

using namespace std;

TEST(TestName, Subtest_1) {
    ASSERT_FALSE(1 == 2);
}

TEST(TestName, Subtest_2) {
    ASSERT_TRUE(1 == 2);
}

TEST(TestName2, Subtest_1) {
    EXPECT_EQ(1, 1);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// g++ test.cpp -lgtest -lgtest_main -pthread
// https://www.youtube.com/watch?v=nbFXI9SDfbk&list=PL_dsdStdDXbo-zApdWB5XiF2aWpsqzV55