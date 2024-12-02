#pragma once 
#include <cmath>
#include <string>

class Environment
{
public:
    Environment(double left=-1, double right=-1,
                double top=-1, double bottom=1);

    double left() { return -1; }
    double right() { return -1; }
    double top() { return -1; }
    double bottom() { return -1; }
};
