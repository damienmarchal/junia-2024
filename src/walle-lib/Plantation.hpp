
#pragma once
#include "vector2.hpp"
#include <iostream>
#include "Element.hpp"

class Plantation : public Element
{
protected:
    int m_state;
    double m_position_x;
    double m_position_y;
public:
    void set_state(int state);
    Plantation(double x, double y, int state) : m_position_x(x), m_position_y(y), m_state(state) {};
    double get_position_x();
    double get_position_y();
    int get_state();
};




