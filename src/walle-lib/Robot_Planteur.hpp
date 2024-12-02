//
// Created by Utilisateur on 28/11/2024.
//

#ifndef ROBOT_PLANTEUR_HPP
#define ROBOT_PLANTEUR_HPP
#include "Robot.hpp"
#include "Environnement.hpp"

/// Un PlantingRobot *est un* Robot
///
class PlantingRobot : public Robot
{
public:
    PlantingRobot(Environment* env) : Robot(env) {};
    void set_seed();
    void aller_reserve();


private:
    int nbr_graines{0};

};

#endif //ROBOT_PLANTEUR_HPP
