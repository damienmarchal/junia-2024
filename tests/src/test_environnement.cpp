#include <gtest/gtest.h>
#include <walle-lib/environnement.hpp>
#include <walle-lib/robot.hpp>

// Validates the behavior of the constructors
TEST(Environnment, test_constructor) {
    // Creates an environment of size 200m x 200m
    Environment e{-100,+100,-100,100};

    EXPECT_NEAR(e.left(), -100, 0.00001);
    EXPECT_NEAR(e.right(), 100, 0.00001);
    EXPECT_NEAR(e.top(), -100, 0.00001);
    EXPECT_NEAR(e.bottom(), 100, 0.00001);
}

TEST(Environnment, test_constructor_invalid_behavior) {
    // Creates an environment of size 200m x 200m but with wrong
    // values.
    EXPECT_THROW(Environment e(100, -100, -100, 100), InvalidBoundariesEnvironmentException);
    
}

TEST(Environnment, test_add_element) {
    // Creates an environment of size 200m x 200m with right values.
    Environment e{-100,100,-100,100};
    Element e1, e2;

    EXPECT_EQ(e.get_elements_number(), 0);
    e.add_element(&e1);
    e.add_element(&e2);
    EXPECT_EQ(e.get_elements_number(), 2);
}

TEST(Environnment, test_add_robot) {
    // Creates an environment of size 200m x 200m with right values.
    Environment e{-100,100,-100,100};
    Robot r1, r2;

    EXPECT_EQ(e.get_elements_number(), 0);
    e.add_element(&r1);
    e.add_element(&r2);
    EXPECT_EQ(e.get_elements_number(), 2);
    EXPECT_EQ(r1.get_environment(), &e);
}
