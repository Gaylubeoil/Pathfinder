#if !defined(UTILITY_H)
#define UTILITY_H
#include <cstdlib>
#include <string>
#include <sstream>

template <typename T>
std::string to_string(T num)
{
    std::stringstream ss;
    ss << num;
    return ss.str();
}

#endif // UTILITY_H
