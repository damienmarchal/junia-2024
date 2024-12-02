//
// Created by Utilisateur on 28/11/2024.
//

#ifndef ROBOT_REBOUCHEUR_HPP
#define ROBOT_REBOUCHEUR_HPP
#include "robot.hpp"

class FillingRobot : public Robot
{
public:
    FillingRobot(Environment* env) : Robot(env) {};
    void reboucher();



private:

};

#endif //ROBOT_REBOUCHEUR_HPP
