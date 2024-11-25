#include <iostream>
#include "../walle-lib/vector2.hpp"
#include "../walle-lib/robot.hpp"

/*
Les unités sont en mètre et radian

*/
int main(int argc, char **argv)
{
    Robot un_robot;

	// init un robot
	std::cout << "Initialisation d'un nouveau robot" << std::endl;

    /// dt en seconde
    double dt = 0.01;
    double t = 0;
    for(t=0;t<10;t+=dt)
    {
        un_robot.set_speed(0.5);
        un_robot.run(dt);
    }	
}
