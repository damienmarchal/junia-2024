//
// Created by tonys on 28/11/2024.
//

#include "Obstacle.hpp"

void Obstacle::set_type(std::string type)
{
    m_type = type;
}

void Obstacle::set_position(double x, double y)
{
    m_position_x = x;
    m_position_y = y;
}

double Obstacle::get_position_x()
{
    return m_position_x;
}

double Obstacle::get_position_y()
{
    return m_position_y;
}

std::string Obstacle::get_type()
{
    return m_type;
}

