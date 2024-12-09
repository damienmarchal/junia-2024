#pragma once 

#include "environnement.hpp"
#include "element.hpp"

namespace RobotEnergyProperties {
    constexpr double MINIMUM_POWER_CONSUMPTION = 5; // W -> the robot consumes at least 5W for its electronic components
    constexpr double MOVING_POWER_CONSUMPTION = 10; // W/m/s/kg -> the robot consumes 10W per second for each m/s of linear speed and for each kg of mass
    constexpr double LOW_BATTERY_THRESHOLD = 0.1; // ratio
}

template <typename T>
T min(T a, T b) {
    return a < b ? a : b;
}

/// Generic robot class inheriting from MovableElement (can move in the environment).
class Robot : public MovableElement
{
public:
    Robot(Environment* e=nullptr, double mass=10, double size=0.5);

    /// Stops the robot.
    void stop();

    enum STATUS { OK, LOW_BATTERY, EMPTY_BATTERY };
    /// update the robot's position and orientation according to its linear and angular speeds.
    int update(double dt) override;

    double get_battery_ratio() const { return battery_ / battery_capacity_; }

    const double get_battery() const { return battery_; }
    void set_battery(double battery) { battery_ = min(battery, battery_capacity_); }

protected:
    virtual int update_battery(double dt);

    double battery_capacity_ = 1e5; // J
    double battery_ = battery_capacity_;
    static unsigned int id_counter;

};

// need to implement the following classes:
// class DiggingRobot : public Robot
// class PantingRobot : public Robot
// class WateringRobot : public Robot