#include "../lib/InputCheck.h"
#include "gtest/gtest.h"

TEST(InputCheckTest, Input)
{
    ASSERT_EQ(InputCheck("1"), 1);
}
TEST(InputCheckTest, An_Input)
{
    ASSERT_EQ(InputCheck("3"), 3);
}
TEST(InputCheckTest, Wr_Input)
{
    ASSERT_EQ(InputCheck("e"), 0);
}
