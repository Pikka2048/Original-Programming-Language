#include "CppUTest/CommandLineTestRunner.h"

TEST_GROUP(TestFuncInc){};

TEST(TestFuncInc, CheckReturnValue)
{
      LONGS_EQUAL(11, 11);
}
int main(int argc, char **argv){
      return CommandLineTestRunner::RunAllTests(argc, argv);
}