#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class MyClass {
    string id;
    public:
        MyClass(string _id) : id(_id) {}
        string GetId() { return id; }
};

TEST(TestName, Subtest_1) {
    ASSERT_FALSE(1 == 2);
}

TEST(TestName, Subtest_2) {
    ASSERT_TRUE(1 == 1);
}

TEST(TestName2, increment_by_5) {
    MyClass mc("root");
    string value = mc.GetId();
    EXPECT_EQ(value, "root");
    ASSERT_STREQ(value.c_str(), "root");
    EXPECT_STREQ(value.c_str(), "root");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// g++ test.cpp -lgtest -lgtest_main -pthread
// https://www.youtube.com/watch?v=nbFXI9SDfbk&list=PL_dsdStdDXbo-zApdWB5XiF2aWpsqzV55