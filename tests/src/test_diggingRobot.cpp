#include <gtest/gtest.h>
#include <walle-lib/diggingRobot.hpp>

TEST(DiggingRobot, test_constructor) {
    Environment e;
    DiggingRobot r(&e, 10, 0.5);

    EXPECT_EQ(r.get_mass(), 10);
    EXPECT_EQ(r.get_size(), 0.5);
    EXPECT_EQ(r.get_position().x(), 0);
    EXPECT_EQ(r.get_position().y(), 0);
    EXPECT_EQ(r.get_label(), "DiggingRobot1");
    EXPECT_EQ(r.get_battery_ratio(), 1);
}

TEST(DiggingRobot, test_digging) {
    Environment e;
    DiggingRobot r(&e, 10, 0.5);

    r.dig();
    EXPECT_EQ(r.update(1), 0); // no hole to dig
    auto h = e.get_elements<Hole>();
    EXPECT_EQ(h.size(), 1);
    EXPECT_EQ(h[0]->get_size(), DiggingRobotProperties::DIGGING_SIZE);
    EXPECT_EQ(h[0]->get_depth(), DiggingRobotProperties::DIGGING_SPEED);
    EXPECT_EQ(h[0]->get_position().x(), r.get_position().x());
    EXPECT_EQ(h[0]->get_position().y(), r.get_position().y());
}

TEST(DiggingRobot, test_filling) {
    Environment e;
    DiggingRobot r(&e, 10, 0.5);

    auto h = e.get_elements<Hole>();
    EXPECT_EQ(h.size(), 0);
    r.fill_soil();
    r.update(1);
    EXPECT_EQ(r.update(1), -1); // no hole to fill


    Hole *hole = new Hole(&e);
    hole->set_position(r.get_position());
    hole->set_depth(1);
    r.update(1);
    h = e.get_elements<Hole>();
    EXPECT_EQ(h.size(), 1); // 1 for the robot and 1 for the hole
    EXPECT_EQ(h[0]->get_depth(), 1-DiggingRobotProperties::FILLING_SPEED);
    EXPECT_EQ(h[0]->get_position().x(), r.get_position().x());
    EXPECT_EQ(h[0]->get_position().y(), r.get_position().y());
}