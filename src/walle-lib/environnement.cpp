//
// Created by PaulQUIQUEMPOIS on 29/11/2024.
//

#include "environnement.hpp"
#include <iostream>

void environnement::set_length()
{
    std::cout << "Entrez la longueur de l'environnement: ";
    std::cin >> this->length;


    //je ne comprend pas la différence :
    //std::cin >> typeOfLand lit l'entrée standard et affecte la valeur à la variable locale typeOfLand.
    //std::cin >> this->typeOfLand lit l'entrée standard et affecte la valeur à l'attribut membre typeOfLand de l'objet courant.


}

void environnement::set_width()
{
    std::cout << "Entrez la largeur de l'environnement: ";
    std::cin >> this->width;

}

void environnement::set_typeOfLand(std::string typeOfLand)
{
    std::cout << "Entrez le type d'environnement: ";
    std::cin >> this->typeOfLand;
}

double environnement::get_length() const {
    return this->length;
}

double environnement::get_width() const {
    return this->width;
}

