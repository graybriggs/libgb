#pragma once

#include "libgb.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> gb::fileread(const std::string filename) {

    std::vector<std::string> data;

    std::ifstream ifs(filename);
    std::string input;

    while (std::getline(ifs, input)) {
        data.push_back(input);
    }
    return data;
}


std::vector<std::string> gb::strtok(const std::string str, const char delim) {

    if (std::size(str) == 0)
        return std::vector<std::string>(0);

    std::vector<std::string> tokens;
    std::string temp = "";
    for (int i = 0; i < std::size(str); i++) {
        if (str[i] == delim) {
            tokens.push_back(temp);
            temp = "";
        }
        else
            temp += str[i];
    }
    tokens.push_back(temp);
    return tokens;
}

// Make it KMP
int gb::substr_freq(const std::string& str, const std::string& substr) {

    std::size_t diff = std::size(str) - std::size(substr);
    int occurences = 0;

    for (std::size_t i = 0; i < diff; ++i) {

        std::size_t j;
        for (j = 0; j < std::size(substr); ++j) {
            if (str[i + j] != substr[j])
                break;
        }
        if (j == std::size(substr))
            occurences++;

    }

    return occurences;
}