#include <map>
#include <string>
#include <vector>

std::vector<std::string> split(std::string input, std::string delimiter);
int get_register(std::string reg);
int get_immd(std::map<std::string, int> labels, std::string immd);
std::string removeDoubleSpace(std::string input);
