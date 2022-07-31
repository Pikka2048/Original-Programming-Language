#include "runcode.h"
#include "node.h"
#include "./utility/DebugUtl.h"

void RunCode(node_t *root)
{
    if (root == nullptr)
    {
        DebugString("root is nullptr exit func");
        return;
    }

    node_t *target;
    target = root->right;

    if (target != nullptr)
    {
        if (target->data == "print" && target->type == LangType::FUNCTION)
        {
            std::cout << target->right->data << std::endl;
        }
        RunCode(target);
    }
    return;
}