#include "opcode.h"
#include <assert.h>
#include <iostream>
#include <ostream>
#include <string>
#include <tuple>

Opcode::opcode Opcode::opcode_of_str(std::string opcode) {
    if (opcode == "ld") {
        return std::make_tuple(55, 0, I_TYPE);
    }
    if (opcode == "l.d") {
        return std::make_tuple(53, 0, I_TYPE);
    }
    if (opcode == "sd") {
        return std::make_tuple(63, 0, I_TYPE);
    }
    if (opcode == "s.d") {
        return std::make_tuple(61, 0, I_TYPE);
    }
    if (opcode == "daddi") {
        return std::make_tuple(24, 0, I_TYPE);
    }
    if (opcode == "daddiu") {
        return std::make_tuple(25, 0, I_TYPE);
    }
    if (opcode == "beq") {
        return std::make_tuple(4, 0, I_TYPE);
    }
    if (opcode == "bne") {
        return std::make_tuple(5, 0, I_TYPE);
    }
    if (opcode == "dadd") {
        return std::make_tuple(0, 44, R_TYPE);
    }
    if (opcode == "dsub") {
        return std::make_tuple(0, 46, R_TYPE);
    }
    if (opcode == "add.d") {
        return std::make_tuple(0, 47, R_TYPE);
    }
    if (opcode == "sub.d") {
        return std::make_tuple(0, 48, R_TYPE);
    }
    if (opcode == "mul.d") {
        return std::make_tuple(0, 49, R_TYPE);
    }
    if (opcode == "div.d") {
        return std::make_tuple(0, 50, R_TYPE);
    }
    if (opcode == "j") {
        return std::make_tuple(2, 0, J_TYPE);
    }
    if (opcode == "halt") {
        return std::make_tuple(1, 0, J_TYPE);
    }
    if (opcode == "nop") {
        return std::make_tuple(3, 0, J_TYPE);
    }
    if (opcode == "dump") {
        return std::make_tuple(44, 0, J_TYPE);
    }
    std::cerr << opcode << std::endl;
    assert(false);
}
