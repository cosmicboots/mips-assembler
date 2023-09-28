#include "labels.h"
#include <assert.h>
#include <iostream>
#include <map>
#include <ostream>
#include <regex>
#include <string>
#include <vector>
#include "utils.h"

Labels::labels Labels::calculate_labels(std::vector<std::string> lines) {
    auto labels = std::map<std::string, int>();
    int cur_address = 0;
    for (auto line = lines.begin(); line != lines.end(); ++line) {
        if (line->rfind("#", 0) == 0) {
            continue;
        }
        auto tokens = split(*line, " ");

        std::regex m("^[a-zA-Z0-9]*$");

        assert(std::regex_match(tokens[0], m));
        assert(tokens[0].length() <= 12);

        if (tokens[1] == ".dfill" && cur_address % 8 != 0) {
            cur_address += 4;
        }

        if (tokens[0] != "") {
            // Add label
            labels[tokens[0]] = cur_address;
        }

        if (tokens[1] == ".dfill") {
            cur_address += 4;
        }

        cur_address += 4;
    }
    return labels;
}
