#include "plantingRobot.hpp"
#include "hole.hpp"
#include <iostream>

unsigned int PlantingRobot::id_counter = 0;

PlantingRobot::PlantingRobot(Environment *e, double mass, double size) : Robot(e, mass, size)
{
    id_counter++;
    label_ = "PlantingRobot" + std::to_string(id_counter);
}

void PlantingRobot::plant()
{
    is_planting_ = true;
}

int PlantingRobot::update(double dt)
{
    if (Robot::update(dt) < 0)
        return -1;
    if (is_planting_)
    {
        // is there an hole?
        auto hole = nearest<Hole>();
        if (hole)
        {
            hole->set_tree_inside(new Tree(environment_));
            std::cout << "Tree planted at " << get_position_x() << ", " << get_position_y() << std::endl;
        }
        else
            return -2;
    }
    is_planting_ = false;
    return 0;
}

int PlantingRobot::update_battery(double dt)
{
    if (is_planting_)
        battery_ -= PlantingRobotProperties::PLANTING_POWER_CONSUMPTION;
    return Robot::update_battery(dt);
}