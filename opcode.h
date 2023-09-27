#include <map>
#include <string>
#include <tuple>
#define I_TYPE 1
#define R_TYPE 2
#define J_TYPE 3

namespace Opcode {
typedef std::tuple<int, int, int> opcode;
opcode opcode_of_str(std::string opcode);
}  // namespace Opcode
