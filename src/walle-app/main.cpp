#include <iostream>
#include <walle-lib/vector2.hpp>

#include <walle-lib/robot.hpp>
#include <walle-lib/PlantingRobot.hpp>

/// Les unités sont en mètre,
int main(int argc, char** argv)
{
    // Créé en mémoire l'environment;
    Environment un_environment{-100,100,-100,100};

	std::cout << "Hello world" << std::endl;

    /// dt en seconde
    double dt = 0.01;
    double t = 0;
    for(t=0;t<10;t+=dt)
    {
    }
}
