#include <iostream>
#include <walle-lib/vector2.hpp>

#include <walle-lib/robot.hpp>

#include "walle-lib/Robot_Planteur.hpp"

/// Les unités sont en mètre,
int main(int argc, char** argv)
{
    // Créé en mémoire l'environment;
    Environment un_environment;

    // Appellé le constructeur en lui passant en paramètre l'environment.
    PlantingRobot RobotPlanteur1 {&un_environment};

    /// dt en seconde
    double dt = 0.01;
    double t = 0;
    for(t=0;t<10;t+=dt)
    {
        un_planting_robot.set_speed(0.5);
        un_planting_robot.set_seed();
    }
}
