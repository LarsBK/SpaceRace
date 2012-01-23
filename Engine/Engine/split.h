/*

#ifndef SPLIT_57UAIDTF

#define SPLIT_57UAIDTF

#include <string>
#include <sstream>
#include <vector>


//Shamelessly taken from http://stackoverflow.com/a/236803


std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while(std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    return split(s, delim, elems);
}

#endif
*/
