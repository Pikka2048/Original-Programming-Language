#include "paser.h"
#include "node.h"
#include "DebugUtl.h"
#include "StringUtl.h"

int main()
{
    node_t *root = MakeRootNode();
    std::string root_str = root->data;
    std::cout << "Root is " << root_str << std::endl;

    node_t *child;
    child = AddNode(root, "Apple");
    std::string child_str = child->data;
    std::cout << "Child is " << child_str << std::endl;

    node_t *grandchild;
    grandchild = AddNode(child, "Grepe");
    std::string grandchild_str = grandchild->data;
    std::cout << "Child is " << grandchild_str << std::endl;

    DebugString("---------------------------");
    DisplayNodeConsole(root);
    DebugString("---------------------------");
    auto readfile = LoadTextFile(".././program.hoge");
    Parse(readfile);
    DebugString("---------------------------");
    std::vector<std::string> test = {",", "!", "?"};
    std::vector<std::string> result2 = split2("Fire?In,The!Hole?Welcome!To,My!World", test);
    for (std::string e : result2)
    {
        DebugString(e);
    }
}