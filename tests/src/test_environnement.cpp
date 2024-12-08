#include <gtest/gtest.h>
#include <walle-lib/environnement.hpp>
#include <walle-lib/robot.hpp>
// Validates the behavior of the constructors
TEST(Environnment, test_constructor) {
    // Creates an environment of size 200m x 200m
    Environment e{-100,+100,-100,100};

    EXPECT_NEAR(e.left(), -100, 0.00001);
    EXPECT_NEAR(e.right(), 100, 0.00001);
    EXPECT_NEAR(e.bottom(), -100, 0.00001);
    EXPECT_NEAR(e.top(), 100, 0.00001);
}

TEST(Environnment, test_constructor_invalid_behavior) {
    // Creates an environment of size 200m x 200m but with wrong
    // values.
    Environment e{100,-100,-100,100};

    EXPECT_GT(e.left(), e.right());
    EXPECT_GT(e.top(), e.bottom());
}

TEST(Environnment, test_add_element) {
    // Creates an environment of size 200m x 200m but with wrong values.
    Environment e{100,-100,-100,100};

    EXPECT_EQ(e.get_nbre_elements(), 0);
    e.add_element("element 1", new Element());
    e.add_element("element 2", new Element());
    EXPECT_EQ(e.get_nbre_elements(), 2);

    //EXPECT_TRUE(false) << "Uncomment the line before";
}

TEST(Environnment, test_add_robot) {
    // Creates an environment of size 200m x 200m but with wrong values.
    Environment e{100,-100,-100,100};

    EXPECT_EQ(e.get_nbre_robots(), 0);
    e.add_robot("Robot 1", new Robot(&e));
    e.add_robot("Robot 2", new Robot(&e));
    EXPECT_EQ(e.get_nbre_robots(), 2);

    //EXPECT_TRUE(false) << "Uncomment the line before";
}

TEST(Environnment, test_get_element) {
    // Creates an environment of size 200m x 200m but with wrong values.
    Environment e{100,-100,-100,100};

    e.add_element("element 1", new Element());

    Element* element = e.get_element("element 1");
    EXPECT_NE(element, nullptr);

    //EXPECT_TRUE(false) << "Uncomment the line before";
}

TEST(Environment, remove_element){
    Environment e{100,-100,-100,100};
    e.add_element("element 1", new Element());
    e.remove_element("element 1");
    EXPECT_EQ(e.get_nbre_elements(), 0);
}