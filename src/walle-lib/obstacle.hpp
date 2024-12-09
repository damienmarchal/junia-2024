#pragma once
#include "element.hpp"

class Obstacle : public Element
{
public:
    Obstacle(Environment *e = nullptr) : Element(e) {}
    Obstacle(Environment *e, double x, double y) : Element(e, x, y) {}
};
