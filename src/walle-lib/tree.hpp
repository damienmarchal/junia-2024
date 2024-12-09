#pragma once

#include "element.hpp"

namespace TreeProperties {
    constexpr double MAX_GROWTH_RATE = 0.1;
    constexpr double MAX_HEIGHT = 10;
    constexpr double MAX_SIZE = 0.6;
    constexpr double MIN_NUTRIENTS = 0.1;
    constexpr double MIN_SIZE = 0.06;
    constexpr double MIN_HEIGHT = 0.5;
}

class Tree : public FixedElement {
    public:
        Tree(Environment *environment = nullptr, double x=0, double y=0);

        void plant();

        void feed(double nutrients);

        int update(double dt) override;

        double get_height() const;

        double get_soil_nutrients() const;

    private:
        double height_{TreeProperties::MIN_HEIGHT};
        double soil_nutrients_{0};
        bool planted_{false};
        static unsigned int id_counter;
};