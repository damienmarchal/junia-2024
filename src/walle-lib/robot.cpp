#include "robot.hpp"
#include "environnement.hpp"
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
    m_omega = vitesse_angulaire;
}

double Robot::get_angular_speed()
{
    return m_omega;
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

void Robot::move_to(double target_x, double target_y, double dt)
{
    while(1)
    {
    double target_theta = atan2(target_y - m_y, target_x - m_x);
    
    double delta_theta = target_theta - m_theta;

    while (delta_theta > M_PI) delta_theta -= 2 * M_PI;
    while (delta_theta < -M_PI) delta_theta += 2 * M_PI;

    if (fabs(delta_theta) > 0.01) { 
        set_angular_speed(delta_theta / dt); 
        set_speed(0); 
    } else { 
        set_angular_speed(0);
        set_speed(0.5); 
    }

    
    run(dt);

    
    double distance_to_target = sqrt(pow(target_x - m_x, 2) + pow(target_y - m_y, 2));
    if (distance_to_target < 0.1) { 
        stop();
        break;
    }
    }
}