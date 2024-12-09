#include <gtest/gtest.h>
#include <walle-lib/robot.hpp>
#include <walle-lib/environnement.hpp>

class MonRobotDeTest : public Robot
{
public:
    MonRobotDeTest(Environment* e) : Robot(e) {};
    double get_battery_capacity(){ return 0.5; }
};

// Validates the behavior of the constructors
TEST(Robot, test_set_speed) {
    Environment e(-100, 100, -100, 100);
    MonRobotDeTest mon_robot{&e};

    mon_robot.set_speed(0.5);
    EXPECT_NEAR(mon_robot.get_speed(), 0.5, 0.00001);

    mon_robot.set_speed(0.7);
    EXPECT_NEAR(mon_robot.get_speed(), 0.7, 0.00001);
}

TEST(Robot, test_angular_speed) {
    Environment e(-100, 100, -100, 100);
    MonRobotDeTest mon_robot{&e};

    mon_robot.set_angular_speed(0.5);
    EXPECT_NEAR(mon_robot.get_angular_speed(), 0.5, 0.00001);

    mon_robot.set_angular_speed(0.7);
    EXPECT_NEAR(mon_robot.get_angular_speed(), 0.7, 0.00001);
}

TEST(Robot, test_move_forward) {
    Environment e(-100, 100, -100, 100);
    MonRobotDeTest mon_robot{&e};
    float x0 = mon_robot.get_position_x();
    float y0 = mon_robot.get_position_y();
    mon_robot.set_speed(0.5);
    mon_robot.run(0.01);
    float x1 = mon_robot.get_position_x();
    float y1 = mon_robot.get_position_y();

    float dx = x1 - x0;
    float dy = y1 - y0;
    float d = sqrt(dx*dx + dy*dy);


    EXPECT_NEAR(d, 0.5*0.01, 0.00001);
}

TEST(Robot, test_move_to) {
    
    Environment e(-100, 100, -100, 100);

    
    Robot test_robot{&e};

    
    float x0 = test_robot.get_position_x();
    float y0 = test_robot.get_position_y();

    
    float target_x = 10.0;
    float target_y = 10.0;

    
    float dt = 0.1;

    test_robot.move_to(target_x, target_y, dt);

        
    float x = test_robot.get_position_x();
    float y = test_robot.get_position_y();
    float dx = target_x - x;
    float dy = target_y - y;
    float distance = sqrt(dx * dx + dy * dy);

        
    

    float final_x = test_robot.get_position_x();
    float final_y = test_robot.get_position_y();
    float final_dx = target_x - final_x;
    float final_dy = target_y - final_y;
    float final_distance = sqrt(final_dx * final_dx + final_dy * final_dy);

    // Le robot doit être très proche de la cible
    EXPECT_NEAR(final_distance, 0.0, 0.1);
}