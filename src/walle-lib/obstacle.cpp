//
// Created by PaulQUIQUEMPOIS on 29/11/2024.
//

#include "obstacle.hpp"
#include <iostream>

void obstacle::createObstacleRand(double numberOfObstacle)
{
    for(int i = 0; i < numberOfObstacle; i++) {
        std::cout << "Création d'un obstacle de taille et position aléatoire" << std::endl;
        double lengthObstacle = rand() % 10 + 1; // longueur entre 1 et 10 mètres
        double widthObstacle = rand() % 10 + 1; // largeur entre 1 et 10 mètres
        double xObstacle = rand() % (int) this->get_length() + 1;    // position x entre 0 et length mètres
        double yObstacle = rand() % (int) this->get_width() + 1;     // position y entre 0 et width mètres
    }
}

void obstacle::setObstacle(double lengthObstacle, double widthObstacle, double xObstacle, double yObstacle)
{
    std::cout << "Entrez la longueur de l'obstacle: ";
    std::cin >> this->lengthObstacle;
    std::cout << "Entrez la largeur de l'obstacle: ";
    std::cin >> this->widthObstacle;
    std::cout << "Entrez la position x de l'obstacle: ";
    std::cin >> this->xObstacle;
    std::cout << "Entrez la position y de l'obstacle: ";
    std::cin >> this->yObstacle;

}

void obstacle::setBase(double xBase, double yBase)
{
    std::cout << "Entrez la  position x de la base: ";
    std::cin >> this->xBase;
    std::cout << "Entrez la  position y de la base: ";
    std::cin >> this->yBase;
}