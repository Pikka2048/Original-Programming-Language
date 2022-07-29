#include "DebugUtl.h"

int DebugString(std::string msg)
{
    if (msg.empty())
        return -1;
    std::cout << msg << std::endl;
    return 0;
}
int DebugString(int msg)
{
    std::cout << msg << std::endl;
    return 0;
}
int DebugString(bool msg)
{
    std::cout << std::boolalpha << msg << std::endl;
    return 0;
}
int DebugStringList(std::vector<std::string> msgs)
{
    for (std::string m : msgs)
    {  
        std::cout << m << std::endl;
    }
    return 0;
}