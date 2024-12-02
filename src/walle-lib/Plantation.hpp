//
// Created by tonys on 28/11/2024.
//

#ifndef PLANTATION_HPP
#define PLANTATION_HPP
#include "vector2.hpp"
#include <iostream>

class Plantation {
protected:
    std::string m_state;
    double m_position_x;
    double m_position_y;
public:
    void set_state(std::string state);
    Plantation(double x, double y, std::string state) : m_position_x(x), m_position_y(y), m_state(state) {};
    double get_position_x();
    double get_position_y();
    std::string get_state();
};



#endif //PLANTATION_HPP
