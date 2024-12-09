#include "wateringRobot.hpp"
#include "tree.hpp"

unsigned int WateringRobot::id_counter = 0;

WateringRobot::WateringRobot(Environment *e, double mass, double size)
    : Robot(e, mass, size)
{
    id_counter++;
    label_ = "WateringRobot" + std::to_string(id_counter);
}

void WateringRobot::water()
{
        is_watering_ = true;
}


void WateringRobot::stop_watering()
{
    is_watering_ = false;
}

int WateringRobot::update(double dt)
{
    if (Robot::update(dt) < 0)
        return -1;
    if (is_watering_)
    {
        // is there a plant?
        auto plant = nearest<Tree>();
        if (plant)
        {
            plant->feed(WateringRobotProperties::WATERING_NUTRIMENT_BOOST*dt);
            battery_ -= WateringRobotProperties::WATERING_POWER_CONSUMPTION*dt;
        }
        else
            return -2;
    }
    return 0;
}

int WateringRobot::update_battery(double dt)
{
    if (is_watering_)
        battery_ -= WateringRobotProperties::WATERING_POWER_CONSUMPTION*dt;
    return Robot::update_battery(dt);
}