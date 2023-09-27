#include <string>
#include <vector>

std::vector<std::string> split(std::string input, std::string delimiter) {
    input = input + " ";
    std::vector<std::string> res;
    size_t pos = 0;
    std::string token;
    while ((pos = input.find(delimiter)) != std::string::npos) {
        token = input.substr(0, pos);
        res.push_back(token);
        input.erase(0, pos + delimiter.length());
    }
    return res;
}
