#include <iostream>
#include <walle-lib/vector2.hpp>
#include <walle-lib/environment.hpp>
#include <walle-lib/element.hpp>
#include <walle-lib/obstacle.hpp>
#include <walle-lib/robot.hpp>
#include <walle-lib/tree.hpp>
#include <walle-lib/planting_robot.hpp>

/*
Les unités sont en mètre et radian
*/

int main(int argc, char **argv)
{
    // init code
    std::cout << "<-- Debut du script... -->" << std::endl;

    // Créé en mémoire l'environment;
    Environment environnement_1{-10, 10, -10, 10};

    /// dt en seconde
    double dt = 0.1;
    double t = 0;

    // Création des robots
    Robot mon_robot_1{&environnement_1, 1.0, 1.0};
    Planting_robot mon_planting_robot_1{&environnement_1, -1.0, -1.0};
    Planting_robot mon_planting_robot_2{&environnement_1, 9.0, -1.0};

    mon_robot_1.set_speed(1.0);
    mon_planting_robot_1.set_speed(0.75);
    mon_planting_robot_2.set_speed(0.75);
    mon_robot_1.set_angular_speed(0.5);
    mon_planting_robot_1.set_angular_speed(0.5);
    mon_planting_robot_2.set_angular_speed(0.25);

    // Création d'obsacles
    Obstacle pierre_1{&environnement_1, 2.0, 2.0};
    Obstacle pierre_2{&environnement_1, -8.0, 3.0};

    // Simulation de la plantation d'arbres et des collisions
    for (t = 0; t < 10; t += dt)
    {
        // Déplacement des robots
        mon_robot_1.run(dt);
        mon_planting_robot_1.run(dt);
        mon_planting_robot_2.run(dt);

        // Plantation d'arbres par les robots
        mon_planting_robot_1.plant();
        mon_planting_robot_2.plant();

        // affichage des positions
        std::cout << "Temps : " << t << std::endl;
        std::cout << "Position du robot : " << mon_robot_1.get_x() << " " << mon_robot_1.get_y() << std::endl;
        std::cout << "Position du planting robot 1 : " << mon_planting_robot_1.get_x() << " " << mon_planting_robot_1.get_y() << std::endl;
        std::cout << "Position du planting robot 2 : " << mon_planting_robot_2.get_x() << " " << mon_planting_robot_2.get_y() << std::endl;
    }

    std::cout << "<-- Fin du script... -->" << std::endl;

    return 0;
}