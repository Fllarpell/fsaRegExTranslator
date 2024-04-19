#pragma once

#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <utility>

#ifndef FSAREGEXTRANSLATOR_INCLUDE_H
#define FSAREGEXTRANSLATOR_INCLUDE_H

std::vector<std::string> split(const std::string &string, char separateSymbol) {
    std::vector<std::string> _separatedWords;
    std::stringstream _word(string);
    while(_word.good()) {
        std::string _good_word_temp;
        getline(_word, _good_word_temp, separateSymbol);
        _separatedWords.push_back(_good_word_temp);
    }

    return _separatedWords;
}

#endif //FSAREGEXTRANSLATOR_INCLUDE_H
