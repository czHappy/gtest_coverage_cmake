#include <gtest/gtest.h>
#include "math.h"

TEST(MathTest, Add) {
    EXPECT_EQ(add(2, 3), 5);
}

TEST(MathTest, Sub) {
    EXPECT_EQ(sub(7, 4), 3);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
