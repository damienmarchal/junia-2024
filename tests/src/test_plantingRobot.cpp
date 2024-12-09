#include <gtest/gtest.h>

#include <walle-lib/plantingRobot.hpp>
#include <walle-lib/hole.hpp>

TEST(PlantingRobot, test_constructor)
{
    PlantingRobot r;
    EXPECT_NEAR(r.get_position_x(), 0.0, 0.00001);
    EXPECT_NEAR(r.get_position_y(), 0.0, 0.00001);
    EXPECT_NEAR(r.get_mass(), 10, 0.00001);
    EXPECT_NEAR(r.get_size(), 0.5, 0.00001);

    PlantingRobot r1(nullptr, 1.0, 2.0);

    EXPECT_EQ(r1.get_label(), "PlantingRobot2");
}

TEST(PlantingRobot, test_plant)
{
    PlantingRobot r;
    Hole h;
    Environment e;
    e.add_element(&r);
    e.add_element(&h);

    h.set_depth(0.2);

    r.plant();

    EXPECT_EQ(e.update(1.0), 0);
    auto trees = e.get_elements<Tree>();
    EXPECT_EQ(trees.size(), 1);
    EXPECT_EQ(trees[0], h.get_tree_inside());
    EXPECT_NEAR(h.get_tree_inside()->get_position_x(), r.get_position_x(), 0.00001);
}