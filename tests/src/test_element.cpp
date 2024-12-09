#include <gtest/gtest.h>
#include <walle-lib/element.hpp>
#include <walle-lib/environment.hpp>

TEST(Element, test_constructor){
    Environment e{0.0, 10.0, 0.0, 10.0};
    Element element_1{&e};
    Element element_2{&e, 1.0, 2.0};

    std::vector<Element *> elements = e.get_elements_list();
    EXPECT_EQ(elements.size(), 2);
    EXPECT_EQ(elements[0], &element_1);
    EXPECT_EQ(elements[1], &element_2);

    elements[0]->set_position(3.0, 4.0);
    EXPECT_NEAR(element_1.get_x(), 3.0, 0.00001);
    EXPECT_NEAR(element_1.get_y(), 4.0, 0.00001);
}

TEST(Element, test_set_position){
    Environment e{0.0, 10.0, 0.0, 10.0};
    Element element_1{&e, 0.0, 0.0};

    element_1.set_position(1.0, 2.0);
    EXPECT_NEAR(element_1.get_x(), 1.0, 0.00001);
    EXPECT_NEAR(element_1.get_y(), 2.0, 0.00001);

    element_1.set_position(3.0, 4.0);
    EXPECT_NEAR(element_1.get_x(), 3.0, 0.00001);
    EXPECT_NEAR(element_1.get_y(), 4.0, 0.00001);
}

TEST(Element, test_set_size){
    Environment e{0.0, 10.0, 0.0, 10.0};
    Element element_1{&e, 0.0, 0.0};

    element_1.set_size(0.5);
    EXPECT_NEAR(element_1.get_size(), 0.5, 0.00001);

    element_1.set_size(0.7);
    EXPECT_NEAR(element_1.get_size(), 0.7, 0.00001);
}