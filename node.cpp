#include "node.h"

node_t *MakeRootNode(std::string data)
{
    node_t *node = new node_t;
    node->data = data;
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