#include "operands.h"
#include <sys/types.h>
#include <charconv>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <variant>
#include <vector>
#include "labels.h"
#include "opcode.h"
#include "utils.h"

int Operands::get_itype(Labels::labels labels,
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
               operands[1] == "beq" || operands[1] == "bne") {
        rt = get_register(operands[2]);
        rs = get_register(operands[3]);
        immd = get_immd(labels, operands[4]);
        if ((operands[1] == "beq" || operands[1] == "bne")
            && (labels.find(operands[4]) != labels.end())
        ) {
            immd -= current_address + 4;  // current_address + 4 = PC
            immd /= 4;  // Ofset is in terms of instructions not bytes
        }
    }

    return (rs & 0x1f) << 21 | (rt & 0x1f) << 16 | (immd & 0xffff);
}

int Operands::get_rtype(std::vector<std::string> operands) {
    auto op = Opcode::opcode_of_str(operands[1]);
    auto funct_code = std::get<1>(op);
    auto rd = get_register(operands[2]);
    auto rs = get_register(operands[3]);
    auto rt = get_register(operands[4]);
    // auto shamt = operands[5];
    return (rs & 0x1f) << 21 | (rt & 0x1f) << 16 | (rd & 0x1f) << 11 |
           (funct_code & 0x3f);
}

int Operands::get_jtype(Labels::labels labels,
                        int current_address,
                        std::vector<std::string> operands) {
    int offset;
    if (operands[1] == "halt" || operands[1] == "nop") {
        offset = 0;
    } else if (operands[1] == "dump") {
        offset = get_immd(labels, operands[2]);
    } else {
        if (labels.find(operands[2]) != labels.end()) {
            offset = get_immd(labels, operands[2]) >> 2;
        } else {
            offset = get_immd(labels, operands[2]);
        }
    }
    return offset & 0x3ffffff;
}
