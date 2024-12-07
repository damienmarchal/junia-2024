#include "hole.hpp"

double Hole::get_depth() const { return depth_; }

void Hole::set_depth(double depth) { depth_ = depth; }

Element *Hole::get_element_inside() const { return element_inside_; }

int Hole::set_element_inside(Element *element_inside)
{
    if (element_inside != nullptr)
    {
        if (element_inside_ != nullptr)
            return -1; // already occupied 
        if (element_inside->get_collision_radius()/2 > get_size())
            return -2; // don't fit
        
        element_inside->set_position(get_position());
    }

    element_inside_ = element_inside;
    return 0;
}