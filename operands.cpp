#include <sys/types.h>
#include <charconv>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int get_register(std::string reg) {
    if (reg.rfind("r", 0) == 0) {
        return std::stoi(reg.substr(1));
    }
    return 0;
}

int get_immd(std::map<std::string, int> labels,
             int current_address,
             std::string immd) {
    int ret = 0;
    if (labels.find(immd) == labels.end()) {
        // Label not found
        ret = std::stoi(immd);
    } else {
        ret = labels[immd] - current_address;
    }
    return ret;
}

int get_itype(std::map<std::string, int> labels,
              int current_address,
              std::vector<std::string> operands) {
    int rt;
    int immd;
    int rs;

    if (operands[1] == "ld" || operands[1] == "l.d" || operands[1] == "sd" ||
        operands[1] == "s.d") {
        rt = get_register(operands[2]);
        immd = get_immd(labels, current_address, operands[3]);
        rs = get_register(operands[4]);
    } else if (operands[1] == "daddi" || operands[1] == "daddiu" ||
               operands[1] == "beq") {
        rt = get_register(operands[2]);
        rs = get_register(operands[3]);
        immd = get_immd(labels, current_address, operands[4]);
    }

    return rt << 16 | rs << 21 | immd;
}

int get_rtype(std::map<std::string, int> labels,
              std::vector<std::string> operands) {
    auto rs = operands[2];
    auto rt = operands[3];
    auto rd = operands[4];
    // auto shamt = operands[5];
    // auto funct = operands[6];
    return 0;
}

int get_jtype(std::map<std::string, int> labels,
              std::vector<std::string> operands) {
    std::string offset;
    if (operands[1] != "halt") {
        offset = operands[2];
    }
    return 0;
}
