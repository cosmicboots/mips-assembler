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

int Operands::get_rtype(std::vector<std::string> operands) {
    auto op = Opcode::opcode_of_str(operands[1]);
    auto funct_code = std::get<1>(op);
    auto rd = get_register(operands[2]);
    auto rs = get_register(operands[3]);
    auto rt = get_register(operands[4]);
    // auto shamt = operands[5];
    // auto funct = operands[6];
    return rs << 21 | rt << 16 | rd << 11 | funct_code;
}

int Operands::get_jtype(Labels::labels labels,
                        int current_address,
                        std::vector<std::string> operands) {
    int offset;
    if (operands[1] == "halt" || operands[1] == "nop") {
        offset = 0;
    } else {
        offset = (get_immd(labels, operands[2]) - current_address) & 0x2ffffff;
    }
    return offset;
}
