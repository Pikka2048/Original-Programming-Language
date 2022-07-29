#include "paser.h"
#include <fstream>
#include <sstream>
#include "./utility/DebugUtl.h"
#include "./utility/StringUtl.h"

// TOKEN : parentheses, doblequotes
std::vector<std::string> PARSE_TOKENS = {"(", ")"};

void Parse(std::string program)
{
    split(program, PARSE_TOKENS);
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
