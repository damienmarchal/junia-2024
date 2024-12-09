#pragma once

#include "Robot.hpp"

class IrrigationRobot : public Robot {
protected:
    double m_water_level{0.5};
    void irrigate(double x, double y);
    // position de la zone de recharge en eau
    
public:
    IrrigationRobot(Environment* env) : Robot(env) {};
};




