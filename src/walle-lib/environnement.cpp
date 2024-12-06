//
// Created by PaulQUIQUEMPOIS on 29/11/2024.
//

#include "environnement.hpp"
#include "obstacle.hpp"
#include "robot.hpp"
#include <iostream>
#include <algorithm>


void Environment::create_envi_rand()
{
    std::cout << "Création d'un environnement de taille et type aléatoire" << std::endl;

    left_ = rand() % 100 + 10; // distance gauche entre 10 et 100 mètres
    right_ = - rand() % 100 + 10; // distance droite entre 10 et 100 mètres
    bottom_ = - rand() % 100 + 10; // distance derrière entre 10 et 100 mètres
    top_ = rand() % 100 + 10; // distance devant entre 10 et 100 mètres

    int random_land = rand() % 3;

    if (random_land == 0)
        this->typeOfLand = "Sable";
    else if (random_land == 1)
        this->typeOfLand = "Roche";
    else
        this->typeOfLand = "Terre";

    this->nbr_of_obstacle = rand() % 15 + 1; // entre 1 et 15 obstacles
}

void Environment::set_typeOfLand()
{
    std::cout << "Type de terrain : " << typeOfLand << std::endl;
}

void Environment::set_nbr_of_obstacle()
{
    std::cout << "Nombre d'obstacles : " << nbr_of_obstacle << std::endl;
}

std::vector<Robot*> Environment::get_objects() {
    std::vector<Robot*> robots;
    for (Element* elem : elements) {
        Robot* robot = dynamic_cast<Robot*>(elem);  // Tentative de cast
        if (robot) {
            robots.push_back(robot);
        }
    }
    return robots;
}

std::vector<Element*> Environment::get_elements() const {
    return elements;  // Retourne simplement le vecteur d'éléments
}


void Environment::add_element(Element* element)
{
    elements.push_back(element);
}

void Environment::add_robot(Element *robot) {
    elements.push_back(static_cast<Element*>(robot));  // Cast explicite
    // Ajouter le robot à la collection d'éléments
}

const std::vector<Robot *> & Environment::get_objects() const {
    return get_objects();
}

void Environment::remove_robot(Robot* robot_to_remove) {
    auto it = std::remove_if(elements.begin(), elements.end(),
                             [robot_to_remove](Element* elem) {
                                 Robot* robot = dynamic_cast<Robot*>(elem);
                                 return robot == robot_to_remove;
                             });

    if (it != elements.end()) {
        std::cout << "Robot retiré de l'environnement." << std::endl;
        elements.erase(it, elements.end());
    } else {
        std::cout << "Robot non trouvé dans l'environnement." << std::endl;
    }
}

void Environment::remove_element(Element* element_to_remove) {
    auto it = std::find(elements.begin(), elements.end(), element_to_remove);
    if (it != elements.end()) {
        elements.erase(it); // Retire l'élément de la liste
    }
}




