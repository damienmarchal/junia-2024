#pragma once

#include <vector>

#include "element.hpp"
#include "robot.hpp"

namespace ChargingStationProperties {
    constexpr double REFUEL_RATE = 100; // W
    constexpr double MIN_DISTANCE_TO_CHARGE = 0.5; // m
}

class ChargingStation : public FixedElement {
    public:
        ChargingStation(Environment *environment = nullptr, double x=0, double y=0);

        int attach(Robot* robot);
        void detach(Robot* robot);
        bool isNear(Robot* robot) const;
        int update(const double dt) override;

    private:
        std::vector<Robot*> robotsInCharge_;
        static unsigned int id_counter;
};