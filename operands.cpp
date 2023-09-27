#include <sys/types.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

int get_register(std::string reg) {
    if (reg.rfind("r", 0) == 0) {
        return std::stoi(reg.substr(1));
    }
    return 0;
}

int get_immd(std::string immd) {
    return std::stoi(immd);
}

int get_itype(std::vector<std::string> operands) {
    int rt;
    int immd;
    int rs;

    if (operands[1] == "ld" || operands[1] == "l.d") {
        rt = get_register(operands[2]);
        immd = get_immd(operands[3]);
        rs = get_register(operands[4]);
    }

    return rs << 16;
}

int get_rtype(std::vector<std::string> operands) {
    auto rs = operands[2];
    auto rt = operands[3];
    auto rd = operands[4];
    // auto shamt = operands[5];
    // auto funct = operands[6];
    return 0;
}

int get_jtype(std::vector<std::string> operands) {
    std::string offset;
    if (operands[1] != "halt") {
        offset = operands[2];
    }
    return 0;
}
