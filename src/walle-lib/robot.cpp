
#include "robot.hpp"

double Robot::get_speed()
{
    return m_speed;
}

void Robot::set_speed(double speed)
{
    m_speed = speed;
}

void Robot::set_angulare_speed(double vitesse_angulaire)
{

}


void Robot::stop()
{
    set_speed(0);
    set_angulare_speed(0);
}

void Robot::run(double dt)
{
    m_x += cos(m_theta) * m_speed * dt ;
    m_y += sin(m_theta) * m_speed * dt ;
    m_theta += m_omega * dt ;
}

#include "robot.hpp"

void avancer(double vitesse) {

}
void tourner(double angle) {

}
void stop() {
    
}