#include "tree.hpp"

unsigned int Tree::id_counter = 0;

Tree::Tree(Environment *environment, double x, double y) : FixedElement(environment, x, y)
{
    id_counter++;
    label_ = "Tree" + std::to_string(id_counter);
    size_ = TreeProperties::MIN_SIZE;
}
void Tree::plant()
{
    collision_radius_ = size_ / 2;
    planted_ = true;
}

void Tree::feed(double nutrients)
{
    soil_nutrients_ += nutrients;
}

int Tree::update(double dt)
{
    if (!planted_)
    {
        return height_;
    }
    const double available_nutrients_ = soil_nutrients_ * size_; // the bigger the tree, the more nutrients it can absorb

    const double available_nutrients_for_growth_height = available_nutrients_ / 2 * (1 - height_ / TreeProperties::MAX_HEIGHT) * dt; // the taller the tree, the less it grows in height
    const double available_nutrients_for_growth_size = available_nutrients_ / 2 * (1 - size_ / TreeProperties::MAX_SIZE) * dt;       // the bigger the tree, the less it grows in size

    height_ += available_nutrients_for_growth_height * TreeProperties::MAX_GROWTH_RATE;
    size_ += available_nutrients_for_growth_size * TreeProperties::MAX_GROWTH_RATE;
    collision_radius_ = size_ / 2;
    soil_nutrients_ -= available_nutrients_for_growth_height + available_nutrients_for_growth_size;

    if (soil_nutrients_ < TreeProperties::MIN_NUTRIENTS)
    {
        soil_nutrients_ = TreeProperties::MIN_NUTRIENTS;
    }

    return 0;
}

double Tree::get_height() const { return height_; }

double Tree::get_soil_nutrients() const { return soil_nutrients_; }