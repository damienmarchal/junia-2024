#include <iostream>
#include <walle-lib/vector2.hpp>

#include <walle-lib/robot.hpp>
#include "walle-lib/diggingRobot.hpp"

/// Les unités sont en mètre,
int main(int argc, char** argv)
{
    // Créé en mémoire l'environment;
    Environment un_environment{-10,10,-10,10};

    DiggingRobot un_robot{&un_environment, 10, 0.5};
    un_robot.set_position(un_environment.center());
    un_robot.set_orientation(0);
    un_robot.set_linear_speed(1);
    un_robot.set_angular_speed(0.5);



	std::cout << "beginning of the simulation" << std::endl;

    /// dt en seconde
    double dt = 0.01;
    double t = 0;
    for(t=0;t<5;t+=dt)
    {
        un_environment.update(dt);
    }
    un_robot.stop();
    un_robot.dig();
    while(un_robot.get_soil_quantity() < 0.2)
    {
        un_environment.update(dt);
    }
    un_robot.stop_digging();
    un_robot.set_linear_speed(0.5);
    for(t=0;t<5;t+=dt)
    {
        un_environment.update(dt);
    }

    std::cout << "end of the simulation" << std::endl;
    return 0;
}
