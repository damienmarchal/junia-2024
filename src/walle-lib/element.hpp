#pragma once
#include "vector2.hpp"

class Environment;

class Element {
    public:

        Element(Environment *environment = nullptr);
        Element(double x, double y, Environment *environment = nullptr);

        double get_position_x() const;
        double get_position_y() const;
        Vector2<double> get_position() const;
        void set_position(double x, double y);
        void set_position(Vector2<double> position);

        double get_orientation() const;
        void set_orientation(double orientation);

        Environment *get_environment() const;
        void set_environment(Environment *environment);
    
    protected :
        Vector2<double> position_{0, 0};
        double orientation_{0};
        double collision_radius_{0};
        Environment *environment_{nullptr};
};

class FixedElement : public Element {
    public:
        FixedElement(Environment *environment = nullptr);
        FixedElement(double x, double y, Environment *environment = nullptr);
};

class MovableElement : public Element {
    public:
        MovableElement(Environment *environment = nullptr);
        MovableElement(double x, double y, Environment *environment = nullptr);

        double get_linear_speed() const;
        void set_linear_speed(double linear_speed);

        double get_angular_speed() const;
        void set_angular_speed(double angular_speed);

        void move_according_velocities(double dt);

    private:
        double linear_speed_{0};
        double angular_speed_{0};
};