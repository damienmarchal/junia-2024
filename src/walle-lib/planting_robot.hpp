#pragma once

#include "robot.hpp"

class Tree;

class Planting_robot : public Robot
{
public:
    Planting_robot(Environment *e = nullptr) : Robot(e) {};
    Planting_robot(Environment *e, double x, double y) : Robot(e, x, y) {};

    Tree* plant();
};
