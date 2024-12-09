#include <gtest/gtest.h>
#include <walle-lib/wateringRobot.hpp>
#include <walle-lib/tree.hpp>

TEST(WateringRobot, test_watering)
{
    Environment e;
    WateringRobot w(&e);
    Tree t(&e);
    double initial_nutrients = t.get_soil_nutrients();
    w.water();
    w.update(1);

    ASSERT_NEAR(t.get_soil_nutrients(), initial_nutrients+WateringRobotProperties::WATERING_NUTRIMENT_BOOST, 0.0001);
}