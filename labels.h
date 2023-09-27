#include <map>
#include <string>
#include <vector>

namespace Labels {
typedef std::map<std::string, int> labels;

labels calculate_labels(std::vector<std::string> lines);
}  // namespace Labels
