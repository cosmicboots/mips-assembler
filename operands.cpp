#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

int get_itype(std::vector<std::string> operands) {
    auto rs = operands[2];
    auto rt = operands[3];
    auto immd = operands[4];
    std::cout << "rs: " << rs << "\trt: " << rt << "\timmd: " << immd
              << std::endl;
    return 0;
}

int get_rtype(std::vector<std::string> operands) {
    auto rs = operands[2];
    auto rt = operands[3];
    auto rd = operands[4];
    // auto shamt = operands[5];
    // auto funct = operands[6];
    std::cout << "rs: " << rs << "\trt: " << rt << "\trd: " << rd << std::endl;
    return 0;
}

int get_jtype(std::vector<std::string> operands) {
    std::string offset;
    if (operands[1] != "halt") {
        offset = operands[2];
    }
    return 0;
}
