#pragma once
#include "vector2.hpp"
#include <string>
#include <vector>

#include "environnement.hpp"

class Element
{
public:
    Element(Environment *environment = nullptr, double x = 0, double y = 0);

    double get_position_x() const;
    double get_position_y() const;
    Vector2<double> get_position() const;
    void set_position(double x, double y);
    void set_position(Vector2<double> position);

    double get_orientation() const;
    void set_orientation(double orientation);

    Environment *get_environment() const;
    void set_environment(Environment *environment);

    double get_size() const;
    void set_size(double size);

    double get_collision_radius() const;
    void set_collision_radius(double collision_radius);

    virtual int update(double dt) = 0;

    std::string get_label() const;

    bool is_size_overlapping(const Element &element) const;

    bool is_colliding(const Element &element) const;

    template <class ElementClass>
    ElementClass *nearest() const
    {
        std::vector<ElementClass *> elements = environment_->get_elements<ElementClass>();
        ElementClass *nearest = nullptr;
        for (ElementClass *element : elements)
        {
            double distance = (element->get_position() - position_).norm2();
            if (!nearest)
                nearest = element;
            else if (distance < (nearest->get_position() - position_).norm2())
                nearest = element;
        }
        return nearest;
    }

protected:
    Vector2<double> position_{0, 0};
    double orientation_{0};
    double collision_radius_{0};
    double size_{0};
    Environment *environment_{nullptr};
    std::string label_;
    static unsigned int id_counter;
};

class FixedElement : public Element
{
public:
    FixedElement(Environment *environment = nullptr, double x = 0, double y = 0);

protected:
    static unsigned int id_counter;
};

class MovableElement : public Element
{
public:
    MovableElement(Environment *environment = nullptr, double x = 0, double y = 0);

    double get_linear_speed() const;
    void set_linear_speed(double linear_speed);

    double get_angular_speed() const;
    void set_angular_speed(double angular_speed);

    double get_mass() const;
    void set_mass(double mass);

    void move_according_speeds(double dt);

protected:
    void collision_handing();

    double linear_speed_{0};
    double angular_speed_{0};
    double mass_{0};
    static unsigned int id_counter;
};