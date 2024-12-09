#pragma once

#include "robot.hpp"

namespace WateringRobotProperties
{
    constexpr double WATERING_POWER_CONSUMPTION = 50; // W
    constexpr double WATERING_NUTRIMENT_BOOST = 0.1;
}

class WateringRobot : public Robot
{
public:
    WateringRobot(Environment *e = nullptr, double mass = 10, double size = 0.5);

    void water();
    void stop_watering();
    int update(double dt) override;

protected:
    static unsigned int id_counter;
    int update_battery(double dt) override;
    bool is_watering_ = false;
};

