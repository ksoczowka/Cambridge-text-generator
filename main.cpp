#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<char> seps = {' ', ',', '.', '!', '?', '\n'};
bool isSep(char);

std::string messLine(std::string);
std::string messWord(std::string);


int main() {
    std::fstream source;
    std::fstream dest;
    source.imbue(std::locale("pl_PL.ISO-8859-2"));
    dest.imbue(std::locale("pl_PL.ISO-8859-2"));
    source.open("Source-text.txt");
    dest.open("Generated-text.txt");

    std::string line;

    while(std::getline(source, line)) {
        dest << messLine(line);
    }
    
    return 0;
}
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
