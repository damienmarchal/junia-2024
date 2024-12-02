//
// Created by Utilisateur on 28/11/2024.
//

#ifndef ROBOT_ARROSEUR_HPP
#define ROBOT_ARROSEUR_HPP
#include "robot.hpp"

class WaterRobot : public Robot
{
public:
    WaterRobot(Environment* env) : Robot(env) {};
    double get_water_quantity() const;
    void arroser();
    void aller_fontaine();


private:
    double Quantité_Eau_act{0};
};

#endif //ROBOT_ARROSEUR_HPP
