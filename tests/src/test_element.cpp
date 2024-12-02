#include <gtest/gtest.h>
#include <walle-lib/element.hpp>

TEST(Element, test_constructor) {

    Element e; // Creates an element with default values
    EXPECT_EQ(e.get_environment(), nullptr); // The element is not in an environment

    Element e2(0.1, -1.3); // Creates an element with specific position
    EXPECT_NEAR(e2.get_position_x(), 0.1, 0.00001); // The initial x position is 0.1
    EXPECT_NEAR(e2.get_position_y(), -1.3, 0.00001); // The initial y position is -1.3
}