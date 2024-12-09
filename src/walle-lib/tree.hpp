#pragma once
#include "element.hpp"

class Tree : public Element
{
public:
    Tree(Environment *e = nullptr) : Element(e) {}
    Tree(Environment *e, double x, double y) : Element(e, x, y) {}

};
