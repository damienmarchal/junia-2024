#pragma once
#include <cmath>
#include <string>
#include "obstacle.hpp"

class Environment;  // Déclaration anticipée d'Environment

/// Décrire un objet.
class Robot : public Element
{
/// tout le monde peut utiliser (même l'extérieur)
public:
    Robot(Environment* e)
            : Element(e), environment(e), id_r(next_id_r++) {}

    int get_id_r() const { return id_r; }

    void set_theta(double theta);
    void set_speed(double linear_speed);
    void set_angular_speed(double angular_speed);

    double get_theta();
    double get_speed();
    double get_angular_speed();

    void stop();

    double get_position_x() { return m_x; }
    double get_position_y() { return m_y; }

    /// Met à jour la position interne à partir de la position(et angle),
    /// de la vitesse (et vitesse_angulaire) et de dt
    void run(double dt);

    /// Affiche les informations du robot
    void dump() const;

    /// Vérifie si le robot est en collision avec un élément
    bool is_colliding(double x, double y, Element *elem) const;

    /// Évite la collision avec un élément
    void avoid_collision(double dt);

    /// retourne la capacity de la batterie.
    double get_battery_capacity();

/// moi et mes enfants on peut y accéder
private:
    int id_r;  // Identifiant unique pour chaque robot
    static int next_id_r;  // Prochaine valeur d'identifiant à utiliser

    double m_x{0};      /// attributs x = x * orientation * vitesse * dt
    double m_y{0};
    double m_theta{0};  /// position angulaire

    double m_speed{0};  /// vitesse linéaire
    double m_omega{0};  /// vitesse angulaire

protected:
    Environment* environment {nullptr}; // pointeur

};