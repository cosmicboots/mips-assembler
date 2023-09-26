#include <cstdio>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include "opcode.h"
#include "operands.h"

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

int main() {
    std::string input =
        " ld r1 sum r0\n\
 ld r2 ten r0\n\
 daddi r3 r0 0\n\
loop dadd r1 r1 r3\n\
 daddi r3 r3 1\n\
 beq r3 r2 end\n\
 j loop\n\
 halt\n\
sum .dfill 0\n\
ten .dfill 10\n\
";
    auto lines = split(input, "\n");
    for (auto line = lines.begin(); line != lines.end(); ++line) {
        auto tokens = split(*line, " ");
        auto op = tokens[1];
        std::tuple<int, int> opcode = opcode_of_str(op);
        int opcode_int = std::get<0>(opcode);
        auto instr_type = std::get<1>(opcode);

        int operands = 0x0000;
        switch (instr_type) {
            case I_TYPE:
                get_itype(tokens);
                break;
            case R_TYPE:
                get_rtype(tokens);
                break;
            case J_TYPE:
                get_jtype(tokens);
                break;
        }

        if (op.rfind(".", 0) == 0) {
            printf("assembler directive: ");
        } else {
            auto instruction = opcode_int << 26 | operands;

            printf("%08x", instruction);
        }
        std::cout << " #" << *line << std::endl;
    }
    return 0;
}
