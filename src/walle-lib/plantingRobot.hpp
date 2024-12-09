#pragma once

#include "robot.hpp"

namespace PlantingRobotProperties
{
    constexpr double PLANTING_POWER_CONSUMPTION = 500; // J
}

class PlantingRobot : public Robot
{
public:
    PlantingRobot(Environment *e = nullptr, double mass = 10, double size = 0.5);

    void plant();
    int update(double dt) override;

protected:
    static unsigned int id_counter;
    int update_battery(double dt) override;
    bool is_planting_ = false;
};
