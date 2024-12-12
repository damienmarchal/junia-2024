#include "map_environnement.hpp"

#include <iostream>
#include <ostream>
#include <vector>
#include <utility>


Map_environnement::Map_environnement()  : tableau_map(taille, std::vector<int>(taille)){
    taille = 4;
    init_map();
}


Map_environnement::Map_environnement(int taille)  : tableau_map(taille, std::vector<int>(taille)){
    this->taille = taille;
    init_map();
}

void Map_environnement::init_map() {
    for (size_t i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {

            // on crée un environnement vide : 0 = rien du tout
            tableau_map[i][j] = 0;
        }
    }

}

void Map_environnement::afficher_map() {

    std::cout << std::endl;
    std::cout << "Voici votre map : " << std::endl;
    std::cout << "0 -> emplacement vide" <<std::endl;
    std::cout << "1 -> arbre " << std::endl;
    std::cout << "2 -> maison " << std::endl;
    std::cout << "4 -> plantation " << std::endl;
    std::cout << "7 -> robot " << std::endl;
    for (const auto& ligne : tableau_map) {
        for (int val : ligne) {
            std::cout << val << "  ";
        }
        std::cout << std::endl;
    }

}

void Map_environnement::ajouter_arbre(int nombre) {
    for (int i = 0; i < nombre; i++) {
        int x;
        int y;
        do {
            x = rand() % taille;
            y = rand() % taille;
            //std::cout << x << " " << y << std::endl;
        }
        while (!emplacement_dispo(x ,y ));


        if (tableau_map[x][y] == 0) {
            tableau_map[x][y] = 1;
            //std::cout << tableau_map[x][y] << std::endl;
        }
        else {
            std::cout << "Impossible d'ajouter un arbre" << std::endl;
        }
    }
}

void Map_environnement::ajouter_maison(int nombre) {
    for (int i = 0; i < nombre; i++) {
        int x;
        int y;
        do {
            x = rand() % (taille-2);
            y = rand() % (taille-2);
            //std::cout << x << " " << y << std::endl;
        }
        while (!emplacement_dispo(x ,y ) && !emplacement_dispo((x+1) ,y ) && !emplacement_dispo(x ,(y+1) ) && !emplacement_dispo((x+1) ,(y+1) ));

        if (emplacement_dispo(x ,y ) && emplacement_dispo((x+1) ,y ) && emplacement_dispo(x ,(y+1) ) && emplacement_dispo((x+1) ,(y+1) )) {
            tableau_map[x][y] = 2;
            tableau_map[x+1][y] = 2;
            tableau_map[x][y+1] = 2;
            tableau_map[x+1][y+1] = 2;
        }

    }
}

bool Map_environnement::emplacement_dispo(int x, int y) {
    if (tableau_map[x][y] == 0) {
        return true;
    }
    else {
        return false;
    }
}


int Map_environnement::get_emplacement(int x, int y) {
    return tableau_map[x][y];
}

void Map_environnement::afficher_type(int nombre) {
    for (size_t i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {

            if (tableau_map[i][j] == nombre) {
                parcelle_plantee.emplace_back(i, j);
            }
        }
    }

    //affichage du tableau
    for (const auto& coord : parcelle_plantee) {
        std::cout << "(" << coord.first << ", " << coord.second << ")" << std::endl;
    }
}

int Map_environnement::get_emplacement_x(int nombre) {
    for (size_t i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            if (tableau_map[i][j] == 7) {
                return i;
            }

        }
    }

    return -1;
}

int Map_environnement::get_emplacement_y(int nombre) {
    for (size_t i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            if (tableau_map[i][j] == 7) {
                return j;
            }

        }
    }
    return -1;
}

int Map_environnement::set_emplacement(int x, int y, int message) {
    if (emplacement_dispo(x ,y)) {
        tableau_map[x][y] = message;
        return message;
    }
    else {
        std::cout << "Impossible d'ajouter un élément" << std::endl;
        return -1;
    }

}

void Map_environnement::ajouter_robot(const Robot& robot) {
   tableau_map[robot.get_position_x()][robot.get_position_y()] = 7;
}

void Map_environnement::remove_robot(const Robot& robot) {
    tableau_map[robot.get_position_x()][robot.get_position_y()] = 0;
}

void Map_environnement::deplacer_robot(const Robot &robot) {
    tableau_map[get_emplacement_x(7)][ get_emplacement_y(7)] = 4;
    tableau_map[robot.get_position_x()][robot.get_position_y()] = 7;
}


