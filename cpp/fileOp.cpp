#include "fileOp.h"
#include <fstream>
#include <sstream>

std::string getAllOfFile(std::string filename){
	std::ifstream in(filename);
	std::ostringstream tmp;
	tmp << in.rdbuf();
	std::string str = tmp.str();
	return str;

}
void SplitString(const std::string& s, std::vector<std::string>& v, const char& c){
  std::string::size_type pos1, pos2;
  pos2 = s.find(c);
  pos1 = 0;
  while(std::string::npos != pos2)
  {
    v.push_back(s.substr(pos1, pos2-pos1));
 
    pos1 = pos2 + 1;
    pos2 = s.find(c, pos1);
  }
  if(pos1 != s.length())
    v.push_back(s.substr(pos1));
}

void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c)
{
  std::string::size_type pos1, pos2;
  pos2 = s.find(c);
  pos1 = 0;
  while(std::string::npos != pos2)
  {
    v.push_back(s.substr(pos1, pos2-pos1));
 
    pos1 = pos2 + c.size();
    pos2 = s.find(c, pos1);
  }
  if(pos1 != s.length())
    v.push_back(s.substr(pos1));
}

void GetConfig(std::unordered_map<std::string, std::string>& conf, const std::string& filename){
  auto fileContent = getAllOfFile(filename);
  std::vector<std::string> splited_content;
  SplitString(fileContent, splited_content, '\n');
  std::vector<std::string> tmp_vec;
  for(auto& part: splited_content){
    SplitString(part, tmp_vec, ' ');
    conf[tmp_vec[0]]=tmp_vec[1];
    tmp_vec.clear();
  }
}