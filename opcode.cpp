#include <string>
#include <tuple>
#include "opcode.h"

std::tuple<int, int> opcode_of_str(std::string opcode) {
    if (opcode == "ld") {
        return std::make_tuple(55, I_TYPE);
    }
    if (opcode == "l.d") {
        return std::make_tuple(53, I_TYPE);
    }
    if (opcode == "sd") {
        return std::make_tuple(63, I_TYPE);
    }
    if (opcode == "s.d") {
        return std::make_tuple(61, I_TYPE);
    }
    if (opcode == "daddi") {
        return std::make_tuple(24, I_TYPE);
    }
    if (opcode == "daddiu") {
        return std::make_tuple(25, I_TYPE);
    }
    if (opcode == "beq") {
        return std::make_tuple(4, I_TYPE);
    }
    if (opcode == "bne") {
        return std::make_tuple(5, I_TYPE);
    }
    if (opcode == "dadd") {
        return std::make_tuple(0, R_TYPE);
    }
    if (opcode == "dsub") {
        return std::make_tuple(0, R_TYPE);
    }
    if (opcode == "add.d") {
        return std::make_tuple(0, R_TYPE);
    }
    if (opcode == "sub.d") {
        return std::make_tuple(0, R_TYPE);
    }
    if (opcode == "mul.d") {
        return std::make_tuple(0, R_TYPE);
    }
    if (opcode == "div.d") {
        return std::make_tuple(0, R_TYPE);
    }
    if (opcode == "j") {
        return std::make_tuple(2, J_TYPE);
    }
    if (opcode == "halt") {
        return std::make_tuple(1, J_TYPE);
    }
    if (opcode == "nop") {
        return std::make_tuple(3, J_TYPE);
    }
    if (opcode == "dump") {
        return std::make_tuple(44, J_TYPE);
    }
    return std::make_tuple(-1, -1);
}
