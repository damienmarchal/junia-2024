#pragma once 
#include <cmath>

class TestRobot;

/// Décrire un objet.
class Robot
{
public:
    void set_speed(double linear_speed);              ///
    void set_angulare_speed(double angular_speed);    ///

    double get_speed();
    double get_angular_speed();

    void stop();

    double get_position_x();
    double get_position_y();

    /// Met à jour la position interne à partir de la position(et angle),
    /// de la vitesse (et vitesse_angulaire) et de dt
    void run(double dt);

    friend TestRobot;

private:
    double m_x{0};      /// attributs x = x * orientation * vitesse * dt
    double m_y{0};
    double m_theta{0};  /// position angulaire

    double m_speed{0};/// vitesse linéaire
    double m_omega{0};  /// vitesse angulaire
};


#ifndef ROBOT_HPP
#define ROBOT_HPP

class Robot
{
public:
    void avancer(double vitesse);
    void tourner(double angle);
    void stop();

    double get_x();
    double get_y();

private:
    double x;     // position x
    double y;     // position y
    double theta; // angle en radians
};

#endif