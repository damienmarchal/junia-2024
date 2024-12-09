#include <gtest/gtest.h>
#include <walle-lib/element.hpp>
#include <walle-lib/environnement.hpp>
#include <walle-lib/robot.hpp>

// Validates the behavior of the constructors
TEST(Environment, test_constructor) {
    // Creates an environment of size 200m x 200m
    Environment e{-100,+100,-100,100};

    EXPECT_NEAR(e.left(), -100, 0.00001);
    EXPECT_NEAR(e.right(), 100, 0.00001);
    EXPECT_NEAR(e.top(), -100, 0.00001);
    EXPECT_NEAR(e.bottom(), 100, 0.00001);
}

TEST(Environment, test_constructor_invalid_behavior) {
    // Creates an environment of size 200m x 200m but with wrong
    // values.
    EXPECT_THROW(Environment e(100, -100, -100, 100), InvalidBoundariesEnvironmentException);
    
}


class TestElement : public Element {
public:
    TestElement(Environment *environment = nullptr, double x = 0, double y = 0) : Element(environment, x, y) {}

    int update(double dt) override {
        return 0;
    }
};

TEST(Environment, test_add_element) {
    // Creates an environment of size 200m x 200m with right values.
    Environment e{-100,100,-100,100};
    TestElement e1, e2;

    EXPECT_EQ(e.get_elements_number(), 0);
    e.add_element(&e1);
    e.add_element(&e2);
    EXPECT_EQ(e.get_elements_number(), 2);
}

TEST(Environment, test_add_robot) {
    // Creates an environment of size 200m x 200m with right values.
    Environment e{-100,100,-100,100};
    Robot r1, r2;

    EXPECT_EQ(e.get_elements_number(), 0);
    e.add_element(&r1);
    e.add_element(&r2);
    EXPECT_EQ(e.get_elements_number(), 2);
    EXPECT_EQ(r1.get_environment(), &e);
}

class TestElement2 : public Element {
public:
    TestElement2(Environment *environment = nullptr, double x = 0, double y = 0) : Element(environment, x, y) {}

    int update(double dt) override {
        return 0;
    }
};
TEST(Environment, test_update) {
    // Creates an environment of size 200m x 200m with right values.
    Environment e{-100,100,-100,100};
    TestElement e1, e2;
    TestElement2 e3;

    e.add_element(&e1);
    e.add_element(&e2);
    e.add_element(&e3);
    EXPECT_EQ(e.update(1), 0);
    EXPECT_EQ(e.update(1), 0);
    EXPECT_NEAR(e.time(), 2, 0.00001);

    EXPECT_EQ(e.get_elements<TestElement>().size(), 2);
    EXPECT_EQ(e.get_elements<Element>().size(), 3);
    EXPECT_EQ(e.get_elements<TestElement2>().size(), 1);
}