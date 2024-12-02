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
    // catch the exception and check the message
    try {
        Environment e{100, -100, -100, 100};
        FAIL() << "Expected std::invalid_argument";
    } catch (const std::invalid_argument& err) {
        EXPECT_EQ(err.what(), std::string("left must be less than right"));
    } catch (...) {
        FAIL() << "Expected std::invalid_argument but caught a different exception.";
    }
    
}

TEST(Environnment, test_add_element) {
    // Creates an environment of size 200m x 200m with right values.
    Environment e{-100,100,-100,100};

    EXPECT_EQ(e.get_elements(), 0);
    e.add_element(new Element());
    e.add_element(new Element());
    EXPECT_EQ(e.get_elements(), 2);
}

TEST(Environnment, test_add_robot) {
    // Creates an environment of size 200m x 200m with right values.
    Environment e{-100,100,-100,100};

    EXPECT_EQ(e.get_elements(), 0);
    e.add_element(new Robot());
    Robot* r = new Robot();
    e.add_element(r);
    EXPECT_EQ(e.get_elements(), 2);
    EXPECT_EQ(r->get_environment(), &e);

}
