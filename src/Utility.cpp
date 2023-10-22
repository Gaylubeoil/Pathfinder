#include "Utility.hpp"
#include <sstream>

std::string to_string(std::size_t num)
{
    std::stringstream ss;
    ss << num;
    return ss.str();
}