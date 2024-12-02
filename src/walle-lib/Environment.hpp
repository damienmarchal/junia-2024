#pragma once
#include <vector>
#include <iostream>
#include "Plantation.hpp"
#include "Obstacle.hpp"

class Environment
{
protected:
    double m_width{10};
    double m_height{10};
    // liste de zones à planter obstacles et autres grace aux coordonnées
    // Pour les plantations il faudrait savoir l'état de la plantation pour savoir quel robot utiliser
    std::vector<Obstacle> m_list_obstacles;
    //liste de plantations
    std::vector<Plantation> m_list_plantations;


public:
    void add_plantation_at(double x, double y, std::string);
    void init_environment( int nb_obstacles, int nb_plantations);
    void add_obstacle_at(double x, double y, std::string);
};





