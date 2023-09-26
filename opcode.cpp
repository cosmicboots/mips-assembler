#include <string>

int opcode_of_str(std::string opcode) {
    if (opcode == "ld") {
        return 55;
    }
    if (opcode == "l.d") {
        return 53;
    }
    if (opcode == "sd") {
        return 63;
    }
    if (opcode == "s.d") {
        return 61;
    }
    if (opcode == "daddi") {
        return 24;
    }
    if (opcode == "daddiu") {
        return 25;
    }
    if (opcode == "beq") {
        return 4;
    }
    if (opcode == "bne") {
        return 5;
    }
    if (opcode == "dadd") {
        return 0;
    }
    if (opcode == "dsub") {
        return 0;
    }
    if (opcode == "add.d") {
        return 0;
    }
    if (opcode == "sub.d") {
        return 0;
    }
    if (opcode == "mul.d") {
        return 0;
    }
    if (opcode == "div.d") {
        return 0;
    }
    if (opcode == "j") {
        return 2;
    }
    if (opcode == "halt") {
        return 1;
    }
    if (opcode == "nop") {
        return 3;
    }
    if (opcode == "dump") {
        return 44;
    }
    return -1;
}
