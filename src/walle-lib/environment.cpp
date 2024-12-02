#include "environment.hpp"
#include <stdexcept>

Environment::Environment(double left, double right, double top, double bottom)
{
    if(left > right || top > bottom)
    {
        throw std::invalid_argument("Invalid environment - Please check the values");
    }
    _left = left;
    _right = right;
    _top = top;
    _bottom = bottom;
}
