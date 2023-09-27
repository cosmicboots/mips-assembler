#include <map>
#include <string>
#include <vector>

std::map<std::string, int> calculate_labels(std::vector<std::string> lines);
int get_register(std::string reg);
int get_immd(std::map<std::string, int> labels, std::string immd);
