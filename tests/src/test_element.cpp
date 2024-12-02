#include <gtest/gtest.h>
#include <walle-lib/element.hpp>

TEST(Element, test_set_type) {
    Environment e{0.0, 10.0, 0.0, 10.0};
    Element element{&e};

    element.set_type("type1");
    EXPECT_STREQ(element.get_type().c_str(), "type1");

    element.set_type("type2");
    EXPECT_STREQ(element.get_type().c_str(), "type2");
}

TEST(Element, test_set_size) {
    Environment e{0.0, 10.0, 0.0, 10.0};
    Element element{&e};

    element.set_size(0.5);
    EXPECT_NEAR(element.get_size(), 0.5, 0.00001);

    element.set_size(0.7);
    EXPECT_NEAR(element.get_size(), 0.7, 0.00001);
}

TEST(Element, test_set_position) {
    Environment e{0.0, 10.0, 0.0, 10.0};
    Element element{&e};

    element.set_position(1.0, 2.0);
    EXPECT_NEAR(element.get_x(), 1.0, 0.00001);
    EXPECT_NEAR(element.get_y(), 2.0, 0.00001);

    element.set_position(3.0, 4.0);
    EXPECT_NEAR(element.get_x(), 3.0, 0.00001);
    EXPECT_NEAR(element.get_y(), 4.0, 0.00001);
}