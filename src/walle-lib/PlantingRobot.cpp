//
// Created by tonys on 28/11/2024.
//

#include "PlantingRobot.hpp"


void PlantingRobot::set_seed()
{
    std::cout << "Seed planted" << std::endl;
}

double PlantingRobot::get_battery_capacity()
{
    return 0.5;
}

void PlantingRobot::set_seed_capacity(double seed_capacity)
{
    m_seed_capacity = seed_capacity;
}

double PlantingRobot::get_seed_capacity()
{
    return m_seed_capacity;
}


