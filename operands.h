#include <map>
#include <string>
#include <vector>

namespace Operands {
int get_itype(std::map<std::string, int> labels,
              int current_address,
              std::vector<std::string> operands);

int get_rtype(std::vector<std::string> operands);

int get_jtype(std::map<std::string, int> labels,
              std::vector<std::string> operands);
}  // namespace Operands
