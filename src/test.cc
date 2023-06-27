#include <gtest/gtest.h>

#include "app/model/cave.h"

TEST(Cave, initSizeFromFile) {
    model::Cave A;
    A.setPath("data/cave/10x10.txt");
    A.initSizeFromFile();
    EXPECT_EQ(A.getRows(), 10);
    EXPECT_EQ(A.getColumns(), 10);
}

TEST(Cave, generateMap) {
    model::Cave A;
    A.generateMap(10, 10, 0);
    EXPECT_EQ(A.getRows(), 10);
    EXPECT_EQ(A.getColumns(), 10);
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}