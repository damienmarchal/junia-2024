#include <gtest/gtest.h>
#include <walle-lib/robot.hpp>

class MonRobotDeTest : public Robot
{
public:
    MonRobotDeTest(Environment *e) : Robot(e) {};
    MonRobotDeTest(Environment *e, double x, double y) : Robot(e, x, y) {};
    double get_battery_capacity() { return 0.5; }
};

// Validates the behavior of the constructors
TEST(Robot, test_set_speed)
{
    Environment e{0.0, 10.0, 0.0, 10.0};
    MonRobotDeTest mon_robot{&e};

    mon_robot.set_speed(0.5);
    EXPECT_NEAR(mon_robot.get_speed(), 0.5, 0.00001);

    mon_robot.set_speed(0.7);
    EXPECT_NEAR(mon_robot.get_speed(), 0.7, 0.00001);
}

TEST(Robot, test_angular_speed)
{
    Environment e{0.0, 10.0, 0.0, 10.0};
    MonRobotDeTest mon_robot{&e};

    mon_robot.set_angular_speed(0.5);
    EXPECT_NEAR(mon_robot.get_angular_speed(), 0.5, 0.00001);

    mon_robot.set_angular_speed(0.7);
    EXPECT_NEAR(mon_robot.get_angular_speed(), 0.7, 0.00001);
}

TEST(Robot, test_move_forward)
{
    Environment e{0.0, 10.0, 0.0, 10.0};
    MonRobotDeTest mon_robot{&e};
    float x0 = mon_robot.get_x();
    float y0 = mon_robot.get_y();
    mon_robot.set_speed(0.5);
    mon_robot.run(0.01);
    float x1 = mon_robot.get_x();
    float y1 = mon_robot.get_y();

    float dx = x1 - x0;
    float dy = y1 - y0;
    float d = sqrt(dx * dx + dy * dy);

    EXPECT_NEAR(d, 0.5 * 0.01, 0.00001);
}

TEST(Robot, test_get_battery_capacity)
{
    Environment e{0.0, 10.0, 0.0, 10.0};
    MonRobotDeTest mon_robot{&e};

    EXPECT_NEAR(mon_robot.get_battery_capacity(), 0.5, 0.00001);
}

TEST(Robot, test_set_size)
{
    Environment e{0.0, 10.0, 0.0, 10.0};
    MonRobotDeTest mon_robot{&e};

    mon_robot.set_size(0.5);
    EXPECT_NEAR(mon_robot.get_size(), 0.5, 0.00001);

    mon_robot.set_size(0.7);
    EXPECT_NEAR(mon_robot.get_size(), 0.7, 0.00001);
}

TEST(Robot, test_get_closest_collision_element)
{
    Environment e{0.0, 10.0, 0.0, 10.0};
    MonRobotDeTest mon_robot_1{&e, 1.0, 1.0};
    Element element_1{&e, 1.0, 1.0};

    mon_robot_1.set_size(0.5);
    element_1.set_size(0.5);

    EXPECT_EQ(e.get_elements(), 2);

    mon_robot_1.set_position(element_1.get_x(), element_1.get_y());

    EXPECT_EQ(mon_robot_1.get_closest_collision_element(), &element_1);

    element_1.set_position(10.0, 10.0);
    EXPECT_EQ(mon_robot_1.get_closest_collision_element(), nullptr);
}

TEST(Robot, test_collision)
{
    Environment e{0.0, 10.0, 0.0, 10.0};
    MonRobotDeTest mon_robot_1{&e, 2.0, 0.0};
    Element element_1{&e, 0.0, 0.0};

    mon_robot_1.set_size(1);
    element_1.set_size(2);

    mon_robot_1.set_speed(1.0);
    mon_robot_1.set_orientation(3.14159);

    mon_robot_1.run(1.0, false);

    EXPECT_NEAR(mon_robot_1.get_x(), 1.0, 0.00001);

    mon_robot_1.gestion_collision();

    EXPECT_NEAR(mon_robot_1.get_x(), 1.5, 0.00001);

    EXPECT_NEAR(mon_robot_1.get_speed(), 0.0, 0.00001);
}