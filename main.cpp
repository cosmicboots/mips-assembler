#include <cstdio>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include "opcode.h"

std::vector<std::string> split(std::string input, std::string delimiter) {
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

int main() {
    std::string input =
        " ld r1 label r0\n\
 ld r1 100 r2\n\
 daddi r1 r2 10\n\
 daddi r1 r2 label\n\
 sd r1 label r0\n\
 beq r2 r3 label\n\
 beq r2 r3 8\n\
";
    auto lines = split(input, "\n");
    for (auto line = lines.begin(); line != lines.end(); ++line) {
        auto tokens = split(*line, " ");
        auto opcode = tokens[1];
        auto opcode_int = opcode_of_str(opcode) << 26;
        int operands = 0x0000;
        if (opcode == "ld" || opcode == "l.d" || opcode == "sd" ||
            opcode == "s.d" || opcode == "daddi" || opcode == "daddiu" ||
            opcode == "beq" || opcode == "bne") {
            // I type instructions
            printf("Reading I type instruction\n");
        } else if (opcode == "dadd" || opcode == "dsub" || opcode == "add.d" ||
                   opcode == "sub.d" || opcode == "mul.d" ||
                   opcode == "div.d") {
            // R type instructions
            printf("Reading R type instruction\n");
        } else if (opcode == "j" || opcode == "halt" || opcode == "nop" ||
                   opcode == "dump") {
            // J type instructions
            printf("Reading J type instruction\n");
        }

        auto instruction = opcode_int | operands;

        printf("%08x\n", instruction);
    }
    return 0;
}
