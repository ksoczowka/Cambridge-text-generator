#include "../inc/funcs.hpp"

#include <algorithm>

std::vector<char> seps = {' ', ',', '.', '!', '?', '\n'};

bool isSep(char buff) {
    for(auto el : seps) {
        if(buff == el)
            return true;
    }
    return false;
}
std::string messLine(std::string line) {
    std::string retStr{};
    std::string buff{};
    for(auto el : line) {
        if(isSep(el)) {
            retStr += messWord(buff);
            retStr += el;
            buff = "";
        } else {
            buff += el;
        }
        
    }
    if(!isSep(line.back())) {
        retStr += messWord(buff);
    }
    return retStr;
}
std::string messWord(std::string word) {
    if((word.begin() != word.end()) && (word.size() > 2)) {
        char buff;
        int it = 1;
        if((word.size() - 1) % 2 == 1) {
            buff = word.at(1);
            word.at(1) = word.at(3);
            word.at(3) = buff;
            it = 4;
        }
        while(it < word.size()) {
            buff = word.at(it);
            word.at(it) = word.at(it + 1);
            word.at(it + 1) = buff;
            it += 2;
        }
    }
    return word;
}
