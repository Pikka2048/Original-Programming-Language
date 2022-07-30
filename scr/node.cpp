#include "node.h"
#include "./utility/DebugUtl.h"
#include <iostream>

node_t *MakeRootNode()
{
    node_t *node = new node_t;
    node->data = "root";
    node->left = nullptr;
    node->right = nullptr;
    node->type = LangType::LANG;
    return node;
}
node_t *AddNode(node_t *pearent, std::string data, LangType type)
{
    node_t *node = new node_t;
    node->data = data;
    node->type = type;
    pearent->right = node;
    pearent->left = nullptr;
    return node;
}

node_t *DisplayNodeConsole(node_t *root)
{
    if (root == nullptr)
    {
        DebugString("root is nullptr exit func");
        return nullptr;
    }
    if (root->data == "root")
    {
        std::string root_str = root->data + " : " + "Language";
        DebugString(root_str);
    }

    node_t *target;
    target = root->right;

    if (target != nullptr)
    {
        std::string type = "";
        switch (target->type)
        {
        case LangType::LANG:
            type = "Language";
            break;
        case LangType::FUNCTION:
            type = "Function";
            break;
        case LangType::STRING:
            type = "String";
            break;

        default:
            break;
        }
        std::string output = target->data + " : " + type;
        DebugString(output);
        DisplayNodeConsole(target);
    }
    return nullptr;
}