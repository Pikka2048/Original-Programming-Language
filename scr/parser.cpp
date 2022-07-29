#include "paser.h"
#include <fstream>
#include <sstream>
#include "./utility/DebugUtl.h"

// TOKEN : parentheses, doblequotes
std::array<std::string, 3> PARSE_TOKENS = {"(", ")", R"(")"};
void Parse(std::string program)
{
    std::cout << program << std::endl;
    DebugString(PARSE_TOKENS[2]);
}
std::string LoadTextFile(std::string filepath)
{
    std::ifstream ifs(filepath);
    std::stringstream buffer;

    if (ifs.fail())
    {
        std::cerr << "Failed to open file : " << filepath << std::endl;
    }

    buffer << ifs.rdbuf();
    return buffer.str();
}
