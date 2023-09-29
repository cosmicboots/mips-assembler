#include <cstdio>
#include <cstdlib>
#include <cstring>
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
    char* x;
    if (argc <= 1) {
        std::cerr << "Pass in a filename" << std::endl;
        exit(1);
    }
    std::ifstream file;
    file.open(argv[1]);
    std::string input((std::istreambuf_iterator<char>(file)),
                      (std::istreambuf_iterator<char>()));

    std::vector<std::string> output;

    {
        // Convert tabs
        long unsigned int pos;
        while ((pos = input.find("\t")) != std::string::npos) {
            input[pos] = ' ';
        }
        input = removeDoubleSpace(input);
    }

    auto lines = split(input, "\n");

    Labels::labels labels = Labels::calculate_labels(lines);

    // std::cerr << "Labels:" << std::endl;
    // for (const auto& [k, v] : labels) {
    //     std::cerr << "labels[" << k << "] = (" << v << ") " << std::endl;
    // }
    // std::cerr << std::endl;

    int current_address = 0;
    for (auto line = lines.begin(); line != lines.end(); ++line) {
        // Comment line
        if (line->rfind("#", 0) == 0) {
            std::cerr << *line << std::endl;
            continue;
        }

        auto tokens = split(*line, " ");
        if (tokens.size() == 1) {
            // Skip empty lines
            std::cout << std::endl;
            continue;
        }
        auto op = tokens[1];

        if (op.rfind(".", 0) == 0) {
            if (tokens[1] == ".dfill") {
                unsigned long long int val;
                if (tokens[2].find(".") != std::string::npos) {
                    double x = std::stod(tokens[2]);
                    memcpy(&val, &x, 8);
                } else {
                    val = get_immd(labels, tokens[2]);
                }
                unsigned int left = val >> 32 & 0xffffffff;
                unsigned int right = val & 0xffffffff;
                if (current_address % 8 != 0) {
                    current_address += 4;
                    asprintf(&x, "%08x\n", 0);
                    output.push_back(x);
                }
                asprintf(&x, "%08x", right);
                output.push_back(x);
                output.push_back(" #" + *line + "\n");
                asprintf(&x, "%08x\n", left);
                output.push_back(x);
                current_address += 8;
            }
        } else {
            Opcode::opcode opcode = Opcode::opcode_of_str(op);
            int opcode_int = std::get<0>(opcode);
            auto instr_type = std::get<2>(opcode);

            int operands = 0x0000;
            switch (instr_type) {
                case I_TYPE:
                    operands =
                        Operands::get_itype(labels, current_address, tokens);
                    break;
                case R_TYPE:
                    operands = Operands::get_rtype(tokens);
                    break;
                case J_TYPE:
                    operands = Operands::get_jtype(labels, tokens);
                    break;
            }
            unsigned int instruction = opcode_int << 26 | operands;

            asprintf(&x, "%08x", instruction);
            output.push_back(x);
            output.push_back(" #" + *line + "\n");
            current_address += 4;
        }
    }

    for (const auto& line : output) {
        std::cout << line;
    }

    return 0;
}
