#pragma once 
#include <cmath>
#include <string>

class Environment
{
public:
    Environment(double left, double right, double top, double bottom);

    double left() { return _left; }
    double right() { return _right; }
    double top() { return _top; }
    double bottom() { return _bottom; }

private:
    double _left;
    double _right;
    double _top;
    double _bottom;
};
