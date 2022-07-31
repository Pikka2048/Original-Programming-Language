#pragma once
#include <string>
#include <iostream>
#include <array>
#include <vector>
#include "node.h"

std::vector<std::string> LangSplit(std::string str);
node_t* Parse(std::string program);
std::string LoadTextFile(std::string path);