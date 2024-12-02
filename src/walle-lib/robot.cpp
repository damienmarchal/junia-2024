#include "robot.hpp"


/// -----------------  ENVIRONMENT  -----------------
void Environment::add_seed_at(double x, double y, std::string)
{
    // TODO
}



/// -----------------  ROBOT  -----------------
double Robot::get_speed()
{
    return m_speed;
}

void Robot::set_speed(double speed)
{
    m_speed = speed;
}

double Robot::get_angular_speed()
{
    return m_omega;
}

void Robot::set_angular_speed(double angular_speed)
{
    m_omega = angular_speed;
}

void Robot::stop()
{
    set_speed(0);
    set_angular_speed(0);
}

void Robot::run(double dt)
{
    m_x += cos(m_theta) * m_speed * dt ;
    m_y += sin(m_theta) * m_speed * dt ;
    m_theta += m_omega * dt ;
}

/// -----------------  PLANTINGROBOT  -----------------
void PlantingRobot::set_seed()
{
    environment->add_seed_at(get_position_x(), get_position_y(), "Oak");
}
