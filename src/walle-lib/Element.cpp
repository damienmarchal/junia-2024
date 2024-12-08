//
// Created by tonys on 28/11/2024.
//

#include "Element.hpp"

void Element::set_type(std::string type)
{
    m_type = type;
}

void Element::set_position(double x, double y)
{
    m_position_x = x;
    m_position_y = y;
}

double Element::get_position_x()
{
    return m_position_x;
}

double Element::get_position_y()
{
    return m_position_y;
}

std::string Element::get_type()
{
    return m_type;
}

