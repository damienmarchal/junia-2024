#include "diggingRobot.hpp"

unsigned int DiggingRobot::id_counter = 0;

DiggingRobot::DiggingRobot(Environment *e, double mass, double size) : Robot(e, mass, size)
{
    id_counter++;
    label_ = "DiggingRobot" + std::to_string(id_counter);
}

void DiggingRobot::dig()
{
    is_digging_ = true;
    stop_filling();
}

void DiggingRobot::stop_digging()
{
    is_digging_ = false;
}

void DiggingRobot::fill_soil()
{
    is_filling_ = true;
    stop_digging();
}

void DiggingRobot::stop_filling()
{
    is_filling_ = false;
}

int DiggingRobot::update(double dt)
{
    Robot::update(dt);

    auto hole = nearest<Hole>();
    if (is_digging_)
    {
        // is there already an hole? if not, create one
        if (!hole)
        {
            hole = new Hole();
            hole->set_position(get_position());
            hole->set_size(DiggingRobotProperties::DIGGING_SIZE);
            environment_->add_element(hole);
        }

        double delta = DiggingRobotProperties::DIGGING_SPEED*dt;
        hole->set_depth(hole->get_depth() + delta);
        soil_quantity_ -= delta;
        mass_ -= delta * DiggingRobotProperties::SOIL_DENSITY;
    }

    if (is_filling_)
    {
        if (!hole)
            return -1; // no hole to fill

        double delta = -DiggingRobotProperties::FILLING_SPEED*dt; // fill
        hole->set_depth(hole->get_depth() + delta);
        soil_quantity_ -= delta;
        mass_ -= delta * DiggingRobotProperties::SOIL_DENSITY;

        if (hole->get_depth() <= 0)
        {
            // environment_->remove_element(hole); todo
            delete hole;
        }

    }
    return 0;
}

int DiggingRobot::update_battery(double dt)
{
    if (is_digging_)
        battery_ -= DiggingRobotProperties::DIGGING_POWER_CONSUMPTION * dt;
    if (is_filling_)
        battery_ -= DiggingRobotProperties::FILLING_POWER_CONSUMPTION * dt;
    return Robot::update_battery(dt);
}