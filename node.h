#pragma once
#include <string>

typedef struct node_t
{
    std::string data;
    struct node_t *left;
    struct node_t *right;
} node_t;

node_t* MakeRootNode();
node_t* AddNode(node_t *pearent,std::string data);
node_t* DisplayNodeConsole(node_t *root);
