#include <iostream>
#include <walle-lib/environnement.hpp>
#include <walle-lib/robot.hpp>
#include <walle-lib/map_environnement.hpp>

/// Les unités sont en mètre,
int main(int argc, char** argv)
{

	std::cout << "Bienvenue sur Fram'Isen Simulator" << std::endl;

	// création de ma carte
	Map_environnement ma_carte(15);

	//ajout de mes obstacles
	ma_carte.ajouter_maison(3);
	ma_carte.ajouter_arbre(20);

	//affichage de la carte
	ma_carte.afficher_map();

	//création de mon robot planteur
	Robot robot1;
	ma_carte.ajouter_robot(robot1);
	ma_carte.afficher_map();

	// réalisation d'un cycle de plantation
	for (int i = 0; i<50; i++) {
		robot1.planter();
		ma_carte.deplacer_robot(robot1);
		ma_carte.afficher_map();
	}


	// affichage de toutes les parcelles plantées par le robot
	std::cout << 'affichage des parcelles plantees' << std::endl;
	ma_carte.afficher_type(4);

	//affichage de la position finale du robot
	std::cout << "Position finale du robot" << std::endl;
	std::cout << "x = " << robot1.get_position_x() << " , y = " << robot1.get_position_y() << std::endl;

}
