//
// Created by tonys on 28/11/2024.
//

#pragma once
#include "robot.hpp"


class PlantingRobot : public Robot
{
public:
    PlantingRobot(Environment* env) : Robot(env) {};

    /// Mecanisme d'héritage fait qu'on à accès à tout ce qui est publique.
    double get_battery_capacity();
public:
    void set_seed();
    void set_seed_capacity(double seed_capacity);
    double get_seed_capacity();

protected:
    double m_seed_capacity{0.5};
    // position de la zone de recharge de graines

};




