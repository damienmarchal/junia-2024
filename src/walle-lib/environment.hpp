#pragma once 
#include <cmath>
#include <string>
#include "element.hpp"
#include "robot.hpp"

class Environment
{
public:
    Environment(double left, double right, double top, double bottom);

    double left() const { return _left; }
    double right() const { return _right; }
    double top() const { return _top; }
    double bottom() const { return _bottom; }

    int get_elements() const { return _elements; }
    void add_element(Element *e);


private:
    double _left;
    double _right;
    double _top;
    double _bottom;

    int _elements = 0;
};
