#include "paser.h"
#include <fstream>
#include <sstream>

void Parse(std::string program)
{
    std::cout << program << std::endl;
}
std::string LoadTextFile(std::string filepath)
{
    std::ifstream ifs(filepath);
    std::stringstream buffer;

    if(ifs.fail()){
        std::cerr << "Failed to open file." << std::endl;
    }

    buffer << ifs.rdbuf();
    return buffer.str();
}