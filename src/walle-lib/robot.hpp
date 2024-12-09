#pragma once 
#include <cmath>
#include <string>



#include "Element.hpp"

class Environment;

/// Décrire un objet.
class Robot 
{
/// tout le monde peut utiliser (même l'extérieur
public:
    Robot(Environment* e) : environment(e) {}

    void set_speed(double linear_speed);              ///
    void set_angular_speed(double angular_speed);    ///

    double get_speed();
    double get_angular_speed();
    

    void stop();

    double get_position_x(){ return m_x; }
    double get_position_y(){ return m_y; }

    /// Met à jour la position interne à partir de la position(et angle),
    /// de la vitesse (et vitesse_angulaire) et de dt
    void run(double dt);

    // fonction pour le déplacement du robot à une position donnée
    void move_to(double x, double y, double dt);

    /// retourne la capacity de la batterie.
    double get_battery_capacity() { return m_battery_capacity; }

/// moi et mes enfants on peut y accéder
private:
    double m_x{0};      /// attributs x = x * orientation * vitesse * dt
    double m_y{0};
    double m_theta{0};  /// position angulaire

    double m_speed{0};/// vitesse linéaire
    double m_omega{0};  /// vitesse angulaire
    double m_battery_capacity{0.5}; /// capacité de la batterie
protected:
    Environment* environment {nullptr}; //pointeur
};

