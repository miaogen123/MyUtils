#pragma once
#include<string>
#include<vector>
#include<unordered_map>

std::string getAllOfFile(std::string filename);
void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c);
void GetConfig(std::unordered_map<std::string, std::string>& conf, const std::string& filename);