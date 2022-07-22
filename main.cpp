#include "paser.h"
#include "node.h"

int main()
{
    node_t *result = MakeRootNode("Hack");
    std::string result_str = result->data;
    std::cout << result_str << std::endl;
}