//
// Created by tonys on 28/11/2024.
//

#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include <iostream>

class Obstacle {
protected:
    double m_position_x;
    double m_position_y;
    std::string m_type;
public:
    Obstacle(double x, double y, std::string type) : m_position_x(x), m_position_y(y), m_type(type) {};
    void set_type(std::string type);
    void set_position(double x, double y);
    double get_position_x();
    double get_position_y();
    std::string get_type();
};



#endif //OBSTACLE_HPP
