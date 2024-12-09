#pragma once

#include <cmath>
#include <string>

#include "environment.hpp"
#include "element.hpp"

class Robot : public Element
{
    /// tout le monde peut utiliser
public:
    Robot(Environment *e = nullptr) : Element(e) {};
    Robot(Environment *e, double x, double y) : Element(e, x, y) {};

    double get_speed() const;
    void set_speed(double linear_speed);

    double get_angular_speed() const;
    void set_angular_speed(double angular_speed);

    void set_orientation(double theta);
   
    void stop();


    double get_orientation() const { return m_theta; }

    double get_size() const { return m_size; }
    void set_size(double size) { m_size = size; }

    Element *get_closest_collision_element() const;    

    /// Met à jour la position interne à partir de la position(et angle),
    /// de la vitesse (et vitesse_angulaire) et de dt
    void run(double dt, bool collision_gestion = true);

    void gestion_collision();

    void set_battery_capacity(double battery_capacity);
    /// retourne la capacity de la batterie.
    double get_battery_capacity() const;

    /// seulement moi peut utiliser
private:
    double m_theta{0}; /// position angulaire

    double m_battery_capacity{0}; /// capacité de la batterie

    double m_speed{0}; /// vitesse linéaire
    double m_omega{0}; /// vitesse angulaire

};

