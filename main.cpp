#include <cstdio>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include "labels.h"
#include "opcode.h"
#include "operands.h"
#include "utils.h"

int main() {
    std::string input =
        " ld r1 sum r0\n\
 ld r2 ten r0\n\
 daddi r3 r0 0\n\
loop dadd r1 r1 r3\n\
 daddi r3 r3 1\n\
 beq r3 r2 end\n\
 j loop\n\
end halt\n\
sum .dfill 0\n\
ten .dfill 10\n\
";
    auto lines = split(input, "\n");

    auto labels = calculate_labels(lines);

    for (const auto& [k, v] : labels)
        std::cout << "m[" << k << "] = (" << v << ") " << std::endl;

    int current_address = 0;
    for (auto line = lines.begin(); line != lines.end(); ++line) {
        auto tokens = split(*line, " ");
        auto op = tokens[1];
        std::tuple<int, int, int> opcode = opcode_of_str(op);
        int opcode_int = std::get<0>(opcode);
        auto instr_type = std::get<2>(opcode);

        int operands = 0x0000;
        switch (instr_type) {
            case I_TYPE:
                operands = get_itype(labels, current_address, tokens);
                break;
            case R_TYPE:
                operands = get_rtype(tokens);
                break;
            case J_TYPE:
                operands = get_jtype(labels, tokens);
                break;
        }

        if (op.rfind(".", 0) == 0) {
            if (tokens[1] == ".dfill") {
                long int val = std::stol(tokens[2]);
                int left = val >> 8 & 0xffffffff;
                int right = val & 0xffffffff;
                printf("%08x", right);
                std::cout << " #" << *line << std::endl;
                printf("%08x\n", left);
                current_address += 8;
            }
        } else {
            auto instruction = opcode_int << 26 | operands;

            printf("%08x", instruction);
            std::cout << " #" << *line << std::endl;
            current_address += 4;
        }
    }
    return 0;
}
