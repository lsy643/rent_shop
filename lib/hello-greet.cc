#include "hello-greet.h"

std::string get_greet(std::string in_str)
{
    std::string result = "Hello " + in_str;
    return result;
}