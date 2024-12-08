#include <iostream>
#include <walle-lib/vector2.hpp>


#include <walle-lib/environnement.hpp>
#include <walle-lib/PlantingRobot.hpp>
#include <walle-lib/DiggingRobot.hpp>
#include <walle-lib/IrrigationRobot.hpp>


/// Les unités sont en mètre,
int main(int argc, char** argv)
{
    // Créé en mémoire l'environment;
    Environment mon_environment{-100,100,-100,100};

	// Création de plantation et d'obstacles
    Plantation* p1 = new Plantation(10,10,"à creuser");
    Plantation* p2 = new Plantation(20,20,"à creuser");
    Element* e1 = new Element(30,30,"obstacle", 10);
    Element* e2 = new Element(40,40,"obstacle", 10);
    // Ajout des plantations au sein de l'environnement
    mon_environment.add_element("plantation 1", p1);
    mon_environment.add_element("plantation 2", p2);
    mon_environment.add_element("obstacle 1", e1);
    mon_environment.add_element("obstacle 2", e2);
    
    // Création de robots
    DiggingRobot* digging_robot1 = new DiggingRobot(&mon_environment);
    PlantingRobot* planting_robot1 = new PlantingRobot(&mon_environment);
    IrrigationRobot* irrigation_robot1 = new IrrigationRobot(&mon_environment);

    // Ajout des robots au sein de l'environnement
    mon_environment.add_robot("digging_robot1", digging_robot1);
    mon_environment.add_robot("planting_robot1", planting_robot1);
    mon_environment.add_robot("irrigation_robot1", irrigation_robot1);

    /// dt en seconde
    double dt = 0.01;
    double t = 0;
    for(t=0;t<10;t+=dt)
    {
        
    }
}
