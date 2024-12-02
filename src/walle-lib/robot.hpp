#pragma once 
#include <cmath>
#include <string>
#include "Environnement.hpp"

/// Décrire un objet.
class Robot
{
/// tout le monde peut utiliser (même l'extérieur
public:
    Robot(Environment* e) : environment(e) {};

    void set_speed(double linear_speed);              ///
    void set_angular_speed(double angular_speed);    ///

    double get_speed() const;
    double get_angular_speed();

    void stop();

    double get_position_x() const;
    double get_position_y() const;

    /// Met à jour la position interne à partir de la position(et angle),
    /// de la vitesse (et vitesse_angulaire) et de dt
    void run(double dt);

    double get_battery_capacity() const;


/// moi et mes enfants on peut y accéder
private:
    double m_x{0};      /// attributs x = x * orientation * vitesse * dt
    double m_y{0};
    double m_theta{0};  /// position angulaire

    double m_speed{0};/// vitesse linéaire
    double m_omega{0};  /// vitesse angulaire
    double batterie_act{100};

protected:
    Environment* environment {nullptr}; //pointeur
};



