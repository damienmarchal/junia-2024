#include "element.hpp"

unsigned int Element::id_counter = 0;
unsigned int FixedElement::id_counter = 0;
unsigned int MovableElement::id_counter = 0;

Element::Element(Environment *environment, double x, double y) : position_(x, y), environment_(environment)
{
    id_counter++;
    label_ = "Element" + std::to_string(id_counter);
    if (environment)
        environment->add_element(this);
}

double Element::get_position_x() const { return position_.x(); }
double Element::get_position_y() const { return position_.y(); }
Vector2<double> Element::get_position() const { return position_; }
void Element::set_position(double x, double y) { position_ = {x, y}; }
void Element::set_position(Vector2<double> position) { position_ = position; }

double Element::get_orientation() const { return orientation_; }
void Element::set_orientation(double orientation) { orientation_ = orientation; }

double Element::get_size() const { return size_; }
void Element::set_size(double size) { size_ = size; }

double Element::get_collision_radius() const { return collision_radius_; }
void Element::set_collision_radius(double collision_radius) { collision_radius_ = collision_radius; }

Environment *Element::get_environment() const { return environment_; }
void Element::set_environment(Environment *environment) { environment_ = environment; }

std::string Element::get_label() const { return label_; }

bool Element::is_size_overlapping(const Element &element) const
{
    return (position_ - element.position_).norm2() < (size_ + element.size_) / 2;
}

bool Element::is_colliding(const Element &element) const
{
    return (position_ - element.position_).norm2() < collision_radius_ + element.collision_radius_;
}

FixedElement::FixedElement(Environment *environment, double x, double y) : Element(environment, x, y)
{
    id_counter++;
    label_ = "FixedElement" + std::to_string(id_counter);
}

MovableElement::MovableElement(Environment *environment, double x, double y) : Element(environment, x, y)
{
    id_counter++;
    label_ = "MovableElement" + std::to_string(id_counter);
}

double MovableElement::get_linear_speed() const { return linear_speed_; }
void MovableElement::set_linear_speed(double linear_speed) { linear_speed_ = linear_speed; }

double MovableElement::get_angular_speed() const { return angular_speed_; }
void MovableElement::set_angular_speed(double angular_speed) { angular_speed_ = angular_speed; }

double MovableElement::get_mass() const { return mass_; }
void MovableElement::set_mass(double mass) { mass_ = mass; }

void MovableElement::move_according_speeds(double dt)
{
    position_ += Vector2<double>{cos(orientation_), sin(orientation_)} * linear_speed_ * dt;
    orientation_ += angular_speed_ * dt;

    collision_handing();
}

void MovableElement::collision_handing()
{
    if (!environment_)
        return;

    for (Element *element : environment_->get_elements<Element>())
    {
        if (element == this || !is_colliding(*element))
            continue;

        Vector2<double> relative_move = (position_ - element->get_position());
        double distance = relative_move.norm2();
        double overlap = collision_radius_ + element->get_collision_radius() - distance;
        relative_move.normalize();

        if (FixedElement *fixed_element = dynamic_cast<FixedElement *>(element))
            position_ += relative_move * overlap; // push the movable element

        else if (MovableElement *movable_element = dynamic_cast<MovableElement *>(element))
        {
            // push both elements according to their masses
            double total_mass = mass_ + movable_element->get_mass();
            position_ += relative_move * overlap * (mass_ / total_mass);
            movable_element->set_position(movable_element->get_position() - relative_move * overlap * (movable_element->get_mass() / total_mass));
        }
    }
}
