#include "../inc/funcs.hpp"

#include <fstream>
#include <iostream>


int main() {
    std::fstream source;
    std::fstream dest;
    source.open("./txt/Source-text.txt");
    dest.open("./txt/Generated-text.txt");

    std::string line;

    while(std::getline(source, line)) {
        dest << messLine(line);
    }
    
    return 0;
}
