#include <iostream>
#include <walle-lib/vector2.hpp>
#include <walle-lib/robot.hpp>

/*
Les unités sont en mètre et radian
*/

int main(int argc, char **argv)
{
    // init code
	std::cout << "<-- Debut du script... -->" << std::endl;

    // Créé en mémoire l'environment;
    Environment un_environment;

    // Appellé le constructeur en lui passant en paramètre l'environment.
    PlantingRobot un_planting_robot {&un_environment};

    /// dt en seconde
    double dt = 0.01;
    double t = 0;
    for(t=0;t<10;t+=dt)
    {
        un_planting_robot.set_speed(0.5);
        un_planting_robot.set_seed();
    }
}
