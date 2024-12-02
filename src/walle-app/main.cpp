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
    Environment un_environment{-100,100,-100,100};

    /// dt en seconde
    double dt = 0.01;
    double t = 0;
    for(t=0;t<10;t+=dt)
    {
    }
}
