#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <array>
#include <algorithm>

std::vector<std::string> split(const std::string &s, char delim);
std::vector<std::string> split2(const std::string &s, std::vector<std::string> delims);
std::vector<std::string> split3(const std::string &s, std::vector<std::string> delims);
std::string split_loop(std::string str,std::vector<std::string> delims);