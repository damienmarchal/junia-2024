
#include "robot.hpp"
#include "environnement.hpp"

#include <iostream>

double Robot::get_theta()
{
    return m_theta;
}

double Robot::get_speed()
{
    return m_speed;
}

void Robot::set_speed(double speed)
{
    m_speed = speed;
}

void Robot::set_theta(double theta)
{
    m_theta = theta;
}


void Robot::set_angular_speed(double vitesse_angulaire)
{
m_omega = vitesse_angulaire;
}

double Robot::get_angular_speed()
{
    return m_omega;
}

void Robot::stop()
{
    set_speed(0);
    set_angular_speed(0);
}

void Robot::run(double dt) {
    // Calcul de la prochaine position
    double new_x = m_x + cos(m_theta) * m_speed * dt;
    double new_y = m_y + sin(m_theta) * m_speed * dt;

    // Vérifie les collisions potentielles
    for (Element* elem : environment->get_elements()) {
        if (elem != this && is_colliding(new_x, new_y, elem)) {
            std::cout << "Collision détectée avec l'élément " << elem->get_id_e() << ". Évitement en cours...\n";
            avoid_collision(dt);
            return; // Évite de continuer le déplacement normal après une collision
        }
    }

    // Mise à jour des coordonnées si pas de collision
    m_x = new_x;
    m_y = new_y;
    m_theta += m_omega * dt;

    std::cout << "*plantation d'un arbre*";
}

// Définition de la variable statique
int Robot::next_id_r = 0;

void Robot::dump() const {
    std::cout << "Robot ID: " << get_id_e() << std::endl;
    std::cout << "Position: (" << m_x << ", " << m_y << ")" << std::endl;
    std::cout << "Vitesse: " << m_speed << " m/s" << std::endl;
    std::cout << "Orientation: " << m_theta << " radians" << std::endl;
}

bool Robot::is_colliding(double x, double y, Element* elem) const {
    double elem_x = elem->get_x_element();
    double elem_y = elem->get_y_element();
    double elem_width = elem->get_width_element();
    double elem_length = elem->get_length_element();

    // Vérifie si la position (x, y) du robot se trouve à l'intérieur de l'élément
    return (x >= elem_x && x <= elem_x + elem_width &&
            y >= elem_y && y <= elem_y + elem_length);
}


void Robot::avoid_collision(double dt) {
    static double distance_since_collision = 0.0;

    if (distance_since_collision == 0.0) {
        std::cout << "Évitement : changement initial d'angle à 90 degrés.\n";
        m_theta += M_PI / 2;  // Tourne temporairement de 90 degrés

        // Simule le déplacement temporaire pour vérifier l'évitement
        double new_x = m_x + cos(m_theta) * m_speed * dt;
        double new_y = m_y + sin(m_theta) * m_speed * dt;

        // Met à jour la position du robot
        m_x = new_x;
        m_y = new_y;

        // Retour à l'angle initial après avoir évité
        m_theta -= M_PI / 2;
    }
}