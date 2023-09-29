#include <assert.h>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int get_register(std::string reg) {
    if (reg.rfind("r", 0) == 0 || reg.rfind("f", 0) == 0) {
        int x = std::stoi(reg.substr(1));
        assert(x >= 0 && x < 32);
        return x;
    }
    return 0;
}

int get_immd(std::map<std::string, int> labels, std::string immd) {
    int ret = 0;
    if (labels.find(immd) == labels.end()) {
        // Label not found
        int count = std::count_if(immd.begin(), immd.end(), isdigit);
        if (immd.rfind("-") == 0) {
            count += 1;
        }
        assert(count == immd.length());
        ret = std::stoi(immd);
    } else {
        ret = labels[immd];
    }
    return ret;
}

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

bool bothAreSpaces(char lhs, char rhs) {
    return (lhs == rhs) && (lhs == ' ');
}

std::string removeDoubleSpace(std::string input) {
    std::string::iterator new_end =
        std::unique(input.begin(), input.end(), bothAreSpaces);
    input.erase(new_end, input.end());
    return input;
}
