//
// Created by tonys on 29/11/2024.
//

#ifndef DIGGING_ROBOT_HPP
#define DIGGING_ROBOT_HPP

#include "Robot.hpp"

class Digging_Robot : public Robot
{
protected:
    void dig(double x, double y);
public:
    Digging_Robot(Environment* env) : Robot(env) {};
};



#endif //DIGGING_ROBOT_HPP
