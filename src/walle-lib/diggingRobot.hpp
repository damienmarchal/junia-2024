#pragma once

#include "robot.hpp"
#include "hole.hpp"

namespace DiggingRobotProperties
{
    constexpr double DIGGING_POWER_CONSUMPTION = 100; // W
    constexpr double DIGGING_SPEED = 0.1;             // m/s
    constexpr double DIGGING_SIZE = 0.3;              // m
    const double FILLING_SPEED = 0.1;                 // m/s
    const double FILLING_POWER_CONSUMPTION = 100;     // W
    const double SOIL_DENSITY = 100;                    // kg/m
}

class DiggingRobot : public Robot
{
public:
    DiggingRobot(Environment *e = nullptr, double mass = 10, double size = 0.5);

    void dig();
    void stop_digging();
    int update(double dt) override;
    void fill_soil();
    void stop_filling();


protected:
    static unsigned int id_counter;
    int update_battery(double dt) override;
    bool is_digging_ = false;
    bool is_filling_ = false;
    double soil_quantity_ = 0;
};