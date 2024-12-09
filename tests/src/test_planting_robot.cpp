#include <gtest/gtest.h>
#include <walle-lib/planting_robot.hpp>
#include <walle-lib/tree.hpp>

TEST(PlantingRobot, Plant)
{
    Environment e(0, 10, 0, 10);
    Planting_robot planting_robot_1(&e, 5, 5);

    EXPECT_EQ(e.get_elements(), 1);

    Tree *t = planting_robot_1.plant();
    EXPECT_NE(t, nullptr);

    EXPECT_EQ(e.get_elements(), 2);
    EXPECT_EQ(e.get_elements_list()[1], t);
}
