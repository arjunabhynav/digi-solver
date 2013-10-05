#ifndef HELPER_H
#define HELPER_H

extern std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);

extern std::vector<std::string> split(const std::string &s, char delim);

extern bool bothAreSpaces(char lhs, char rhs);

#endif
