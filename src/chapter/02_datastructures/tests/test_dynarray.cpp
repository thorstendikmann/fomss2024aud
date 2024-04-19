#include <gtest/gtest.h>

#include "dynarray/dynarray.h"

typedef fom::AuD::Array<int> Array;

TEST(DynArrayTest, BasicAssertions)
{
    Array array;

    array.push_back(10);
    array.push_back(15);
    array.push_back(1);
    array.push_back(25);
    
    EXPECT_EQ(array.size(), 4);
    EXPECT_EQ(array[0], 10);
    EXPECT_EQ(array[1], 15);
    EXPECT_EQ(array[2], 1);
    EXPECT_EQ(array[3], 25);

    EXPECT_NE(array[2], 4);
    
    array.sort_simple();
    EXPECT_EQ(array[0], 1);
    EXPECT_EQ(array[1], 10);
}