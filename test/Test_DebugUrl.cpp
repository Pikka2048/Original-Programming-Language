#include "CppUTest/CommandLineTestRunner.h"
#include "../scr/utility/DebugUtl.h"
#include <string>

TEST_GROUP(TestDebugString){};

TEST(TestDebugString, Check_It_If_Works_String)
{
    std::string msg = "test msg";
    int result = DebugString(msg);

    LONGS_EQUAL(result, 0);
}
TEST(TestDebugString, Check_It_If_Works_Int)
{
    int msg = 2525;
    int result = DebugString(msg);

    LONGS_EQUAL(result, 0);
}
TEST(TestDebugString, Check_It_If_Works_Bool)
{
    bool msg = true;
    int result = DebugString(msg);

    LONGS_EQUAL(result, 0);
}
