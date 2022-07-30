#pragma once
#include <string>

enum class LangType
{
    LANG,
    FUNCTION,
    STRING,
};

typedef struct node_t
{
    std::string data;
    struct node_t *left;
    struct node_t *right;
    LangType type;
} node_t;

node_t *MakeRootNode();
node_t *AddNode(node_t *pearent, std::string data,LangType type);
node_t *DisplayNodeConsole(node_t *root);
