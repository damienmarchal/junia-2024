#include <gtest/gtest.h>
#include <walle-lib/robot.hpp>

class MonRobotDeTest : public Robot
{
public:
    MonRobotDeTest(Environment* e) : Robot(e) {};
    double get_battery_capacity(){ return 0.5; }
};

// Validates the behavior of the constructors
TEST(Robot, test_set_speed) {
    Environment e;
    MonRobotDeTest mon_robot{&e};

    mon_robot.set_speed(0.5);
    EXPECT_NEAR(mon_robot.get_speed(), 0.5, 0.00001);

    mon_robot.set_speed(0.7);
    EXPECT_NEAR(mon_robot.get_speed(), 0.7, 0.00001);
}

TEST(Robot, test_angular_speed) {
    Environment e;
    MonRobotDeTest mon_robot{&e};

    mon_robot.set_angular_speed(0.5);
    EXPECT_NEAR(mon_robot.get_angular_speed(), 0.5, 0.00001);

    mon_robot.set_angular_speed(0.7);
    EXPECT_NEAR(mon_robot.get_angular_speed(), 0.7, 0.00001);
}

TEST(Robot, test_move_forward) {
    Environment e;
    MonRobotDeTest mon_robot{&e};

    mon_robot.set_angular_speed(0.5);
    mon_robot.run(0.01);

    /// TODO n'oublie de finir ce test.
    EXPECT_FALSE(true);
}
