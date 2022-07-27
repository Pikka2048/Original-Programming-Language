#include "CppUTest/CommandLineTestRunner.h"
#include "../scr/StringUtl.h"
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
    LONGS_EQUAL(6, answer);
}
int main(int argc, char **argv)
{
    return CommandLineTestRunner::RunAllTests(argc, argv);
}