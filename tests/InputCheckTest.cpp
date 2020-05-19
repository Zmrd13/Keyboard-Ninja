#include "gtest/gtest.h"
#include "../lib/InputCheck.h"

TEST(InputCheckTest,RightInput){
ASSERT_EQ(InputCheck("1"),1);
}
TEST(InputCheckTest,ExitInput){
ASSERT_EQ(InputCheck("exit"),1337);
}
TEST(InputCheckTest,WrongInput){
ASSERT_EQ(InputCheck("wqr"),0);
}