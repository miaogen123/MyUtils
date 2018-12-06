#include "fileOp.h"
#include <fstream>
#include<sstream>

std::string getAllOfFile(std::string filename){
	std::ifstream in(filename);
	std::ostringstream tmp;
	tmp << in.rdbuf();
	std::string str = tmp.str();
	return str;

}
