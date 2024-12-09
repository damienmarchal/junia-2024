//
// Created by tonys on 28/11/2024.
//

#include "Plantation.hpp"

void Plantation::set_state(int state)
{
    m_state = state;
}

double Plantation::get_position_x()
{
    return m_position_x;
}

double Plantation::get_position_y()
{
    return m_position_y;
}

int Plantation::get_state()
{
    return m_state;
}