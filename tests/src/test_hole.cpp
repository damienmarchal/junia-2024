#include <gtest/gtest.h>
#include <walle-lib/hole.hpp>
#include <walle-lib/tree.hpp>

// Validates the behavior of the constructors
TEST(Hole, test_constructor)
{
    Hole h;

    EXPECT_NEAR(h.get_position_x(), 0.0, 0.00001);
    EXPECT_NEAR(h.get_position_y(), 0.0, 0.00001);

    Hole h1(nullptr, 1.0, 2.0);

    EXPECT_NEAR(h1.get_position_x(), 1.0, 0.00001);
    EXPECT_NEAR(h1.get_position_y(), 2.0, 0.00001);
}

TEST(Hole, test_set_tree_inside)
{
    Hole h;
    Tree t;
    h.set_position(1.0, 2.0);
    h.set_size(0.5);
    h.set_depth(0.2);
    EXPECT_EQ(h.set_tree_inside(&t),0);
    EXPECT_EQ(h.get_tree_inside(), &t);
    EXPECT_EQ(h.get_tree_inside()->get_position_x(), 1.0);
    EXPECT_EQ(h.get_tree_inside()->get_position_y(), 2.0);

    h.set_tree_inside(nullptr);
    EXPECT_EQ(h.get_tree_inside(), nullptr);
}