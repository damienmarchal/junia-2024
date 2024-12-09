#include "robot.hpp"

double Robot::get_speed() const
{
    return m_speed;
}

void Robot::set_speed(double speed)
{
    m_speed = speed;
}

double Robot::get_angular_speed() const
{
    return m_omega;
}

void Robot::set_angular_speed(double angular_speed)
{
    m_omega = angular_speed;
}

void Robot::set_orientation(double theta)
{
    m_theta = theta;
}

void Robot::stop()
{
    set_speed(0);
    set_angular_speed(0);
}

void Robot::run(double dt, bool collision_gestion)
{
    m_x += cos(m_theta) * m_speed * dt;
    m_y += sin(m_theta) * m_speed * dt;
    m_theta += m_omega * dt;

    // gestion des collisions
}

void Robot::set_battery_capacity(double battery_capacity)
{
    m_battery_capacity = battery_capacity;
}

double Robot::get_battery_capacity() const
{
    return m_battery_capacity;
}

Element *Robot::get_closest_collision_element() const
{
    std::vector<Element *> elements = environment->get_elements_list();

    double max_overlap = 0;
    Element *closest_element = nullptr;
    for (Element *element : elements)
    {
        if (element == this)
        {
            continue;
        }

        double dx = element->get_x() - m_x;
        double dy = element->get_y() - m_y;
        double distance = sqrt(dx * dx + dy * dy);
        double overlap = element->get_size() + m_size - distance;
        if (overlap > max_overlap)
        {
            max_overlap = overlap;
            closest_element = element;
        }
    }

    return closest_element;
}

void Robot::gestion_collision()
{
    Element *closest_element = get_closest_collision_element();
    if (closest_element == nullptr)
        return;
    stop();

    double dx = closest_element->get_x() - m_x;
    double dy = closest_element->get_y() - m_y;
    double distance = sqrt(dx * dx + dy * dy);
    double overlap = (closest_element->get_size() + m_size) / 2 - distance;
    if (overlap > 0)
    {
        m_x -= dx / distance * overlap;
        m_y -= dy / distance * overlap;
    }
}