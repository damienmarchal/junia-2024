//
// Created by PaulQUIQUEMPOIS on 29/11/2024.
//

#include "obstacle.hpp"
#include "environnement.hpp"

void Element::set_length_element(double length)
{
    length_element = length;
}

void Element::set_width_element(double width)
{
    width_element = width;
}

void Element::set_x_element(double x)
{
    x_element = x;
}

void Element::set_y_element(double y)
{
    y_element = y;
}

double Element::get_length_element()
{
    return length_element;
}

double Element::get_width_element()
{
    return width_element;
}

double Element::get_x_element()
{
    return x_element;
}

double Element::get_y_element()
{
    return y_element;
}

// Définition de la variable statique
int Element::next_id_e = 0;
