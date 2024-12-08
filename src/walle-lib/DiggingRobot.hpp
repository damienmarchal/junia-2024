//
// Created by tonys on 29/11/2024.
//

#pragma once

#include "Robot.hpp"

class DiggingRobot : public Robot
{
protected:
    void dig(double x, double y);
public:
    DiggingRobot(Environment* env) : Robot(env) {};
};




