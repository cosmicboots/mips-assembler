#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string>
#include <vector>
#include "labels.h"
#include "opcode.h"
#include "operands.h"
#include "utils.h"

int main(int argc, char** argv) {
    if (argc <= 1) {
        std::cerr << "Pass in a filename" << std::endl;
        exit(1);
    }
    auto file = std::ifstream(argv[1]);
    std::string input((std::istreambuf_iterator<char>(file)),
                      (std::istreambuf_iterator<char>()));

    {
        // Convert tabs
        int pos;
        while ((pos = input.find("\t")) != std::string::npos) {
            input[pos] = ' ';
        }
    }

    auto lines = split(input, "\n");

    Labels::labels labels = Labels::calculate_labels(lines);

    std::cerr << "Labels:" << std::endl;
    for (const auto& [k, v] : labels) {
        std::cerr << "labels[" << k << "] = (" << v << ") " << std::endl;
    }
    std::cerr << std::endl;

    int current_address = 0;
    for (auto line = lines.begin(); line != lines.end(); ++line) {
        // Comment line
        if (line->rfind("#", 0) == 0) {
            std::cout << *line << std::endl;
            continue;
        }

        auto tokens = split(*line, " ");
        if (tokens.size() == 1) {
            // Skip empty lines
            std::cout << std::endl;
            continue;
        }
        auto op = tokens[1];
        Opcode::opcode opcode = Opcode::opcode_of_str(op);
        int opcode_int = std::get<0>(opcode);
        auto instr_type = std::get<2>(opcode);

        int operands = 0x0000;
        switch (instr_type) {
            case I_TYPE:
                operands = Operands::get_itype(labels, current_address, tokens);
                break;
            case R_TYPE:
                operands = Operands::get_rtype(tokens);
                break;
            case J_TYPE:
                operands = Operands::get_jtype(labels, current_address, tokens);
                break;
        }

        if (op.rfind(".", 0) == 0) {
            if (tokens[1] == ".dfill") {
                long int val = get_immd(labels, tokens[2]);
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
