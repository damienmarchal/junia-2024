//
// Created by Utilisateur on 28/11/2024.
//

#ifndef ROBOT_CREUSEUR_HPP
#define ROBOT_CREUSEUR_HPP
#include "robot.hpp"

class DiggingRobot : public Robot
{
public:
    DiggingRobot(Environment* env) : Robot(env) {};
    void creuser();



private:

};

#endif //ROBOT_CREUSEUR_HPP