#include <sys/types.h>
#include <charconv>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <variant>
#include <vector>
#include "opcode.h"

int get_register(std::string reg) {
    if (reg.rfind("r", 0) == 0) {
        return std::stoi(reg.substr(1));
    }
    return 0;
}

int get_immd(std::map<std::string, int> labels, std::string immd) {
    int ret = 0;
    if (labels.find(immd) == labels.end()) {
        // Label not found
        ret = std::stoi(immd);
    } else {
        ret = labels[immd];
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
        immd = get_immd(labels, operands[3]);
        rs = get_register(operands[4]);
    } else if (operands[1] == "daddi" || operands[1] == "daddiu" ||
               operands[1] == "beq") {
        rt = get_register(operands[2]);
        rs = get_register(operands[3]);
        immd = get_immd(labels, operands[4]);
        if (operands[1] == "beq") {
            immd -= current_address + 7;
        }
    }

    return rt << 16 | rs << 21 | immd;
}

int get_rtype(std::vector<std::string> operands) {
    auto op = opcode_of_str(operands[1]);
    auto funct_code = std::get<1>(op);
    auto rd = get_register(operands[2]);
    auto rs = get_register(operands[3]);
    auto rt = get_register(operands[4]);
    // auto shamt = operands[5];
    // auto funct = operands[6];
    return rs << 21 | rt << 16 | rd << 11 | funct_code;
}

int get_jtype(std::map<std::string, int> labels,
              std::vector<std::string> operands) {
    int offset;
    if (operands[1] == "halt" || operands[1] == "nop") {
        offset = 0;
    } else {
        offset = get_immd(labels, operands[2]);
    }
    return offset;
}
