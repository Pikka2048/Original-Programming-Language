#include "paser.h"
#include "node.h"
#include "DebugUtl.h"
#include "StringUtl.h"

void Example()
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
    std::vector<std::string> delims = {"(", ")", R"(")"};
    ;
    std::vector<std::string> result = split3(R"(print("Hello My Lang"))", delims);
    for (std::string x : result)
    {
        std::cout << x << "\n";
    }
}

int main()
{
    Example();
}
