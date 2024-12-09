
#include "robot.hpp"
#include <cmath>

unsigned int Robot::id_counter = 0;

Robot::Robot(Environment *e, double mass, double size) : MovableElement(e)
{
    id_counter++;
    label_ = "Robot" + std::to_string(id_counter);
    set_size(size);
    set_mass(mass);

    if (e)
        e->add_element(this);
}

void Robot::stop()
{
    set_linear_speed(0);
    set_angular_speed(0);
}

int Robot::update(double dt)
{
    MovableElement::move_according_speeds(dt);
    auto battery_status = update_battery(dt);
    if (battery_status == Robot::STATUS::EMPTY_BATTERY)
        return Robot::STATUS::EMPTY_BATTERY;
    if (battery_status == Robot::STATUS::LOW_BATTERY)
        return Robot::STATUS::LOW_BATTERY;

    return 0;
}

int Robot::update_battery(double dt)
{
    battery_ -= RobotEnergyProperties::MINIMUM_POWER_CONSUMPTION * dt;
    battery_ -= RobotEnergyProperties::MOVING_POWER_CONSUMPTION * get_linear_speed() * get_mass() * dt;

    if (battery_ <= 0)
    {
        stop();
        return Robot::Robot::STATUS::EMPTY_BATTERY;
    }
    if (battery_ < RobotEnergyProperties::LOW_BATTERY_THRESHOLD * battery_capacity_)
        return Robot::STATUS::LOW_BATTERY;

    return Robot::STATUS::OK;
}
