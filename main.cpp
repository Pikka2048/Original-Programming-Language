#include "paser.h"
#include "node.h"

int main()
{
    node_t *root = MakeRootNode("Hack");
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
}