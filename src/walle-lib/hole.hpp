#pragma once

#include "element.hpp"


class Hole : public FixedElement {
    public:
        Hole(Environment *environment = nullptr, double x=0, double y=0): FixedElement(environment, x, y) {}

        double get_depth() const;
        void set_depth(double depth);

        Element* get_element_inside() const;
        int set_element_inside(Element* element_inside);


    private:
        double depth_{0};
        Element* element_inside_{nullptr};
};