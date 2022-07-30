#include "paser.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include "node.h"
#include "Token.h"
#include "./utility/DebugUtl.h"
#include "./utility/StringUtl.h"

// TOKEN : parentheses, doblequotes
std::vector<std::string> PARSE_TOKENS = {"(", ")"};

void Parse(std::string program)
{
    node_t *root = MakeRootNode();
    node_t *node_current = root;
    std::vector<std::string> splitted = split(program, PARSE_TOKENS);
    // DebugStringList(splitted);

    for (size_t loop = 0; splitted.size(); loop++)
    {
        if (splitted[loop].empty())
            break;
        std::string current = splitted[loop];
        // Find Element by current
        // found == true : this element is defined LANG TOKEN
        bool found = std::find(LANG_TOKEN.begin(), LANG_TOKEN.end(), current) != LANG_TOKEN.end();
        if (found)
        {
            node_t *child = AddNode(node_current, current);
            node_current = child;
        }
    }
    DisplayNodeConsole(root);
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
