#include "planting_robot.hpp"
#include "tree.hpp"

Tree* Planting_robot::plant()
{
    if (environment == nullptr)
        return nullptr;

    // planter l'arbre a la droite du robot
    Tree *t = new Tree();
    double plant_dangle = get_orientation() + M_PI / 2;
    double dx = cos(plant_dangle);
    double dy = sin(plant_dangle);
    double plant_distance = get_size() / 2 + t->get_size() / 2 +0.1;
    double x = m_x + dx * plant_distance;
    double y = m_y + dy * plant_distance;
    t->set_position(x, y);
    environment->add_element(t);

    return t;
}