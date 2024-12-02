//
// Created by Utilisateur on 28/11/2024.
//

#include "Robot_Planteur.hpp"
#include "robot.hpp"

void PlantingRobot::set_seed()
{
    environment->add_seed_at(get_position_x(), get_position_y(), "Oak");
    nbr_graines=nbr_graines-1;
}

void PlantingRobot::aller_reserve()
{

}