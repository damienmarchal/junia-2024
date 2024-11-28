#include <iostream>
#include <walle-lib/vector2.hpp>

/*
Les unités sont en mètre et radian

/*
Les unités sont en mètre et radian

*/
int main(int argc, char **argv)
{
    // Créé en mémoire l'environment;
    Environment un_environment;

    // Appellé le constructeur en lui passant en paramètre l'environment.
    PlantingRobot un_planting_robot {&un_environment};

	// init un robot
	std::cout << "Initialisation d'un nouveau robot" << std::endl;

    /// dt en seconde
    double dt = 0.01;
    double t = 0;
    for(t=0;t<10;t+=dt)
    {
        un_planting_robot.set_speed(0.5);
        un_planting_robot.set_seed();
    }
}
