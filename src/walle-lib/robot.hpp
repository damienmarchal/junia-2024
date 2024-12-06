#pragma once

#include <cmath>
#include <string>

#include "environment.hpp"

class Robot
{
    /// tout le monde peut utiliser
public:
    Robot(Environment *e = nullptr) : environment(e) {};

    double get_speed() const;
    void set_speed(double linear_speed);

    double get_angular_speed() const;
    void set_angular_speed(double angular_speed);
   
    void stop();

    double get_position_x() const { return m_x; }
    double get_position_y() const { return m_y; }

    double get_orientation() const { return m_theta; }

    double get_size() const { return m_size; }
    void set_size(double size) { m_size = size; }
    

    /// Met à jour la position interne à partir de la position(et angle),
    /// de la vitesse (et vitesse_angulaire) et de dt
    void run(double dt);

    /// retourne la capacity de la batterie.
    virtual double get_battery_capacity() = 0;

    /// seulement moi peut utiliser
private:
    double m_x{0}; /// position x
    double m_y{0}; /// position y
    double m_theta{0}; /// position angulaire

    double m_speed{0}; /// vitesse linéaire
    double m_omega{0}; /// vitesse angulaire

    double m_size{0}; /// taille du robot

    /// seulement moi et mes enfants peuvent utiliser
protected:
    Environment *environment{nullptr}; // pointeur
};

