#pragma once

#include <string>
#include <vector>

namespace gb {

    std::vector<std::string> fileread(const std::string filename);
    std::vector<std::string> strtok(const std::string str, const char delim);

    int substr_freq(const std::string& str, const std::string& substr);
}