#include "element.hpp"

Element::Element(Environment *environment, double x, double y) : position_(x,y), environment_(environment) {}

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

FixedElement::FixedElement(Environment *environment, double x, double y) : Element(environment, x, y ) {}

MovableElement::MovableElement(Environment *environment, double x, double y) : Element(environment, x, y) {}

double MovableElement::get_linear_speed() const { return linear_speed_; }
void MovableElement::set_linear_speed(double linear_speed) { linear_speed_ = linear_speed; }

double MovableElement::get_angular_speed() const { return angular_speed_; }
void MovableElement::set_angular_speed(double angular_speed) { angular_speed_ = angular_speed; }

double MovableElement::get_mass() const { return mass_; }
void MovableElement::set_mass(double mass) { mass_ = mass; }

void MovableElement::move_according_velocities(double dt) {
    position_ += Vector2<double>{cos(orientation_), sin(orientation_)} * linear_speed_ * dt;
    orientation_ += angular_speed_ * dt;
}
