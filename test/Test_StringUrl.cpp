#include "CppUTest/CommandLineTestRunner.h"
#include "../scr/utility/StringUtl.h"
#include <vector>
#include <string>

TEST_GROUP(TestSplit1){};

TEST(TestSplit1, CheckReturnValue)
{
    std::vector<std::string> result;
    std::vector<std::string> delims = {"!", "?", "@", "#,", "$"};
    std::string test_string = "Don't?get#in@my$way,!";
    
    result = split(test_string, delims);
    int answer = 6;
    LONGS_EQUAL(result.size(), answer);
}