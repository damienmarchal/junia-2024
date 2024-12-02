#pragma once
#include "vector2.hpp"

class Environment;

class Element {
    public:
        friend class Environment; // Environment needs to access the protected members of Element

        Element(Environment *environment = nullptr) : environment_(environment) {}
        Element(double x, double y, Environment *environment = nullptr) : position_(x,y), environment_(environment) {}

        double get_position_x() const { return position_.x(); }
        double get_position_y() const { return position_.y(); }
        Vector2<double> get_position() const { return position_; }

        Environment *get_environment() const { return environment_; }
    
    protected :
        Vector2<double> position_{0, 0};
        double collision_radius_{0};
        Environment *environment_{nullptr};
};
