#include <iostream>
#include <walle-lib/vector2.hpp>

#include <walle-lib/robot.hpp>

/// Les unités sont en mètre,
int main(int argc, char** argv)
{
    // Créé en mémoire l'environment;
    Environnement un_environment;

    // Appellé le constructeur en lui passant en paramètre l'environment.
    PlantingRobot un_planting_robot {&un_environment};

	std::cout << "Hello world" << std::endl;

    /// dt en seconde
    double dt = 0.01;
    double t = 0;
    for(t=0;t<10;t+=dt)
    {
        RobotPlanteur1.set_speed(0.5);
        RobotPlanteur1.set_seed();
    }
}
