//
// Created by tonys on 28/11/2024.
//

#pragma once

#include <iostream>

class Element {
protected:
    double m_position_x;
    double m_position_y;
    std::string m_type;
    double m_size;
public:
    Element() : m_position_x(0), m_position_y(0), m_type("default"), m_size(0) {};
    Element(double x, double y, std::string type, double size) : m_position_x(x), m_position_y(y), m_type(type), m_size(size) {};
    void set_type(std::string type);
    void set_position(double x, double y);
    double get_position_x();
    double get_position_y();
    std::string get_type();
    void set_size(double size);
};




