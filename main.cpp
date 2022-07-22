#include "paser.h"
#include "node.h"

int main()
{
    node_t *root = MakeRootNode("Hack");
    std::string root_str = root->data;
    std::cout << "Root is" << root_str << std::endl;

    node_t *result;
    result = AddNode(root,"Apple");
    std::string result_str = result->data;
    std::cout << "Child is" << result_str << std::endl;
}