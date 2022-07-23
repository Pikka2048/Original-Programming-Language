#include "node.h"
#include <iostream>

node_t *MakeRootNode()
{
    node_t *node = new node_t;
    node->data = "root";
    node->left = nullptr;
    node->right = nullptr;
    return node;
}
node_t *AddNode(node_t *pearent, std::string data)
{
    node_t *node = new node_t;
    node->data = data;
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
    node_t * target;
    target = root->right;

    if (target != nullptr)
    {
        DebugString(target->data);
        DisplayNodeConsole(target);
    }
}

void DebugString(std::string msg)
{
    std::cout << msg << std::endl;
}