//
// Created by Utilisateur on 28/11/2024.
//

#ifndef ENVIRONNEMENT_HPP
#define ENVIRONNEMENT_HPP
#include <string>

class Environment
{
public:
    void add_seed_at(double x, double y, std::string)
    {}
    void generer_carte();

private:
    double dimension_carte{16};
    int nombre_obstacle{10};
    int nombre_fontaine{1};
    int nombre_reserve{1};
};

#endif //ENVIRONNEMENT_HPP
