#include <iostream>
#include "robot.hpp"

Robot::Robot() {
    m_x = 7;
    m_y = 3;
    m_theta = 0;
}

Robot::~Robot() {
    std::cout << "Destruction du Robot " << std::endl;
}

double Robot::get_speed() const
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

void Robot::set_position(int x, int y) {
    this -> m_x = x;
    this -> m_y = y;
}

double Robot::get_angular_speed() const
{

    return 1;
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

void Robot::planter() {
    int deplacement = rand() % 4 ;
    if (deplacement == 0) {
        if (m_x > 1 && m_x < 13) {
            m_x ++;
        }
        else {
            m_x = m_x - 1;
        }
    }
    else if (deplacement == 1) {
        if (m_y > 1 && m_y < 13) {
            m_y ++;
        }
        else {
            m_y = m_y - 1;
        }
    }
    else if (deplacement == 2) {
        if (m_x > 1 && m_x < 13) {
            m_x = m_x - 1;
        }
        else {
            m_x = m_x + 1;
        }
    }
    else if (deplacement == 3) {
        if (m_y > 1 && m_y < 13) {
            m_y = m_y -1;
        }
        else {
            m_y = m_y + 1;
        }
    }
}

