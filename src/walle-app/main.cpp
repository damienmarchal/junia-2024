#include <iostream>
#include <walle-lib/vector2.hpp>

#include <walle-lib/robot.hpp>

/// Les unités sont en mètre,
int main(int argc, char** argv)
{
    // Créé en mémoire l'environment;
    Environment un_environment{-100,100,-100,100};

    un_environment.left();

	std::cout << "Hello world" << std::endl;
    std::cout << "Hello Thomas 123Soleil" << std::endl;

    Robot mon_robot{&un_environment};
    mon_robot.get_position_x();

    /// dt en seconde
    double dt = 0.01;
    double t = 0;
    for(t=0;t<10;t+=dt)
    {
    }
}
