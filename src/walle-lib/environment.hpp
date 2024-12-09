#pragma once 
#include <cmath>
#include <string>
#include <vector>
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

    double get_left() const { return _left; }
    double get_right() const { return _right; }
    double get_top() const { return _top; }
    double get_bottom() const { return _bottom; }

    int get_elements() const { return _elements_list.size(); }
    std::vector<Element *> get_elements_list() const { return _elements_list; }
    void add_element(Element *e);


private:
    double _left;
    double _right;
    double _top;
    double _bottom;

    std::vector<Element *> _elements_list;
};
