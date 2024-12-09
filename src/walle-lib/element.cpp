#include "element.hpp"
#include "environment.hpp"

Element::Element(Environment *e) : environment(e)
{
    if (environment != nullptr)
    {
        environment->add_element(this);
    }
}

Element::Element(Environment *e, double x, double y) : m_x(x), m_y(y), environment(e)
{
    if (environment != nullptr)
    {
        environment->add_element(this);
    }
}

void Element::set_position(double x, double y)
{
    m_x = x;
    m_y = y;
}