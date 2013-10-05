#include <vector>
#include <string>
#include <sstream>

#include "helper.h"

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems)
{
  std::stringstream ss(s);
  std::string item;
  while(getline(ss, item, delim))
    elems.push_back(item);
  return elems;
}

std::vector<std::string> split(const std::string &s, char delim)
{
  std::vector<std::string> elems;
  split(s, delim, elems);
  return elems;
}

bool bothAreSpaces(char lhs, char rhs)
{
  return (lhs == rhs) && (lhs == ' ');
}
