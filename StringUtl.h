#pragma once
#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> split(const std::string &s, char delim);
std::vector<std::string> split2(const std::string &s, std::vector<std::string> delims);