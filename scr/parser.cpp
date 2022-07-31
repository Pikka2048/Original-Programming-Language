#include "paser.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Token.h"
#include "./utility/DebugUtl.h"
#include "./utility/StringUtl.h"

// TOKEN : parentheses, doblequotes
std::vector<std::string> PARSE_TOKENS = {"(", ")"};

std::vector<std::string> LangSplit(std::string str)
{
    std::vector<std::string> splitted = split(str, PARSE_TOKENS);
    std::vector<std::string> results;
    for (size_t i = 0; i < splitted.size(); i++)
    {
        int dq_find_first = splitted[i].find(LANG_TOKEN_SYMBOL[0]);
        int dq_find_last = splitted[i].rfind(LANG_TOKEN_SYMBOL[0]);
        if ((dq_find_first != -1) && (dq_find_last != -1))
        {
            results.push_back(R"(")");
            std::string content = splitted[i].substr(dq_find_first, dq_find_last - dq_find_first);
            results.push_back(content);
            results.push_back(R"(")");
            break;
        }
        results.push_back(splitted[i]);
    }

    return results;
}

node_t* Parse(std::string program)
{
    node_t *root = MakeRootNode();
    node_t *node_current = root;

    // DebugStringList(splitted);
    // std::vector<std::string> splitted = LangSplit(program);
    std::vector<std::string> splitted = split(program, PARSE_TOKENS);
    for (size_t loop = 0; loop < splitted.size(); loop++)
    {
        std::string current = splitted[loop];
        // Find Element by current
        // found == true : this element is defined LANG TOKEN
        bool found = std::find(LANG_TOKEN_FUNC.begin(), LANG_TOKEN_FUNC.end(), current) != LANG_TOKEN_FUNC.end();
        if (found)
        {
            node_t *child = AddNode(node_current, current, LangType::FUNCTION);
            node_current = child;
        }
        else
        {
            int dq_find_first = current.find(LANG_TOKEN_SYMBOL[0]);
            int dq_find_last = current.rfind(LANG_TOKEN_SYMBOL[0]);
            if ((dq_find_first != -1) && (dq_find_last != -1))
            {
                std::string content = current.substr(dq_find_first + 1, dq_find_last - dq_find_first - 1);
                node_t *child = AddNode(node_current, content, LangType::STRING);
                node_current = child;
            }
        }
    }
    // DebugStringList(splitted);
    //DisplayNodeConsole(root);
    return root;
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
