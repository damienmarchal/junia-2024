#include "hole.hpp"

unsigned int Hole::id_counter = 0;

Hole::Hole(Environment *environment, double x, double y) : FixedElement(environment, x, y)
{
    id_counter++;
    label_ = "Hole" + std::to_string(id_counter);
}

double Hole::get_depth() const { return depth_; }

void Hole::set_depth(double depth) { depth_ = depth; }

Tree *Hole::get_tree_inside() const { return tree_inside_; }

int Hole::set_tree_inside(Tree *tree_inside)
{
    if (tree_inside != nullptr)
    {
        if (tree_inside_ != nullptr)
            return -1; // already occupied 
        if (!fit(tree_inside))
            return -2; // don't fit
        
        tree_inside->set_position(get_position());
    }

    tree_inside_ = tree_inside;
    return 0;
}

bool Hole::fit(Tree *tree) const
{
    if (tree == nullptr)
        return false;

    const bool deep_enough = get_depth() >= 0.2*tree->get_height();
    const bool not_too_deep = get_depth() <= 0.5*tree->get_height();
    const bool large_enough = get_size() >= tree->get_collision_radius()/2;

    return deep_enough && not_too_deep && large_enough;
}