#include "Environment.hpp"
#include <iostream>
void Environment::add_plantation_at(double x, double y, std::string) {
    // Ajout dans la liste de plantation
    m_list_plantations.push_back(Plantation{x, y, "Plantation"});
}
void Environment::add_obstacle_at(double x, double y, std::string) {
    // Ajout dans la liste d'obstacles
    m_list_obstacles.push_back(Obstacle{x, y, "Obstacle"});
}

void Environment::init_environment( int nb_obstacles, int nb_plantations) {
    // Créer des obstacles et des plantations de graines à des endroits aléatoires

    for (int i = 0; i < nb_obstacles; i++)
    {
        // le nombre aléatoire est un double entre 0 et la taille de l'environnement
        add_obstacle_at(double(rand()) / m_width, rand() / m_height, "Obstacle");
    }
    for (int i = 0; i < nb_plantations; i++)
    {
        add_plantation_at(double(rand()) / m_width, double(rand()) / m_height, "Plantation");
    }
}