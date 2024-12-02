
#include "robot.hpp"

double Robot::get_speed()
{
    return m_speed;
}

void Robot::set_speed(double speed)
{
    m_speed = speed;
}

void Robot::set_angular_speed(double vitesse_angulaire)
{

}

double Robot::get_angular_speed()
{

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
