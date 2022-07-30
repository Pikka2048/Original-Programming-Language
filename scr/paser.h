#pragma once
#include <string>
#include <iostream>
#include <array>
#include <vector>

std::vector<std::string> LangSplit(std::string str);
void Parse(std::string program);
std::string LoadTextFile(std::string path);