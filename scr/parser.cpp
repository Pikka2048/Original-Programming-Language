#include "paser.h"
#include <fstream>
#include <sstream>
#include "node.h"
#include "./utility/DebugUtl.h"
#include "./utility/StringUtl.h"

// TOKEN : parentheses, doblequotes
std::vector<std::string> PARSE_TOKENS = {"(", ")"};

void Parse(std::string program)
{
    std::vector<std::string> result = split(program, PARSE_TOKENS);
    DebugStringList(result);

    node_t *root = MakeRootNode();
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
