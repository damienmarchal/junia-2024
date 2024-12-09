#include <gtest/gtest.h>
#include "walle-lib/tree.hpp"

TEST(Tree, test_constructor)
{
    Tree t;

    EXPECT_NEAR(t.get_height(), TreeProperties::MIN_HEIGHT, 0.00001);
}

/// A tree should grow in size and height when fed with nutrients
TEST(Tree, test_growth)
{
    Tree t;

    t.plant();
    t.feed(1);

    Vector2 last_grow_state{t.get_size(), t.get_height()};
    for (int i = 0; i < 100; i++)
    {
        t.update(100);
        // std::cout << "Height: " << t.get_height() << " Size: " << t.get_size() << std::endl;
        EXPECT_GE(t.get_size(), TreeProperties::MIN_SIZE);
        EXPECT_LE(t.get_size(), TreeProperties::MAX_SIZE);
        EXPECT_GE(t.get_height(), TreeProperties::MIN_HEIGHT);
        EXPECT_LE(t.get_height(), TreeProperties::MAX_HEIGHT);
        EXPECT_GT(t.get_size(), last_grow_state.x());
        EXPECT_GT(t.get_height(), last_grow_state.y());
        
    }
}