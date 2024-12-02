#include <gtest/gtest.h>
#include <walle-lib/element.hpp>

TEST(Element, test_set_type) {
    Environment e;
    Element element{&e};

    element.set_type("type1");
    EXPECT_STREQ(element.get_type().c_str(), "type1");

    element.set_type("type2");
    EXPECT_STREQ(element.get_type().c_str(), "type2");
}

TEST(Element, test_set_size) {
    Environment e;
    Element element{&e};

    element.set_size(0.5);
    EXPECT_NEAR(element.get_size(), 0.5, 0.00001);

    element.set_size(0.7);
    EXPECT_NEAR(element.get_size(), 0.7, 0.00001);
}