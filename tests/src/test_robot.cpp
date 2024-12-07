#include <gtest/gtest.h>
#include <walle-lib/robot.hpp>
#include <cmath>

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

    mon_robot.set_linear_speed(0.5);
    EXPECT_NEAR(mon_robot.get_linear_speed(), 0.5, 0.00001);

    mon_robot.set_linear_speed(0.7);
    EXPECT_NEAR(mon_robot.get_linear_speed(), 0.7, 0.00001);
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
    float x0 = mon_robot.get_position_x();
    float y0 = mon_robot.get_position_y();
    mon_robot.set_linear_speed(0.5);
    mon_robot.run(0.01);
    float x1 = mon_robot.get_position_x();
    float y1 = mon_robot.get_position_y();

    float dx = x1 - x0;
    float dy = y1 - y0;
    float d = sqrt(dx*dx + dy*dy);


    EXPECT_NEAR(d, 0.5*0.01, 0.00001);
}
