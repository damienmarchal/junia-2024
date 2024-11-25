#include <gtest/gtest.h>
#include <walle-lib/robot.hpp>


// Validates the behavior of the constructors
TEST(Robot, test_set_speed) {
  Robot mon_robot;

  mon_robot.set_speed(0.5);
  EXPECT_NEAR(mon_robot.get_speed(), 0.5, 0.00001);

  mon_robot.set_speed(0.7);
  EXPECT_NEAR(mon_robot.get_speed(), 0.7, 0.00001);
}
