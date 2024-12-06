#include <iostream>
#include <walle-lib/vector2.hpp>
#include <walle-lib/environnement.hpp>
#include <walle-lib/robot.hpp>

#pragma execution_character_set("utf-8")


int main() {
    // Créer l'environnement (taille 200x200 m)
    Environment e{100, -100, -100, 100};

    // Créer des obstacles et les ajouter à l'environnement
    Element* obstacle1 = new Element(&e);
    obstacle1->set_x_element(2.0);
    obstacle1->set_y_element(0.0);
    obstacle1->set_width_element(1.0);
    obstacle1->set_length_element(1.0);
    e.add_element(obstacle1);

    Element* obstacle2 = new Element(&e);
    obstacle2->set_x_element(4.0);
    obstacle2->set_y_element(2.0);
    obstacle2->set_width_element(1.0);
    obstacle2->set_length_element(2.0);
    e.add_element(obstacle2);

    // Ajouter deux autres obstacles
    Element* obstacle3 = new Element(&e);
    obstacle3->set_x_element(6.0);
    obstacle3->set_y_element(-3.0);
    obstacle3->set_width_element(3.0);
    obstacle3->set_length_element(5.0);
    e.add_element(obstacle3);

    Element* obstacle4 = new Element(&e);
    obstacle4->set_x_element(-3.0);
    obstacle4->set_y_element(5.0);
    obstacle4->set_width_element(4.0);
    obstacle4->set_length_element(4.0);
    e.add_element(obstacle4);

    // Créer des robots et les ajouter à l'environnement
    Robot* r1 = new Robot(&e);
    r1->set_speed(1.0);  // Vitesse du robot
    r1->set_theta(0);    // Direction initiale (vers la droite)
    e.add_element(r1);

    Robot* r2 = new Robot(&e);
    r2->set_speed(1.0);  // Vitesse du robot
    r2->set_theta(M_PI / 2);  // Direction initiale (vers le haut)
    e.add_element(r2);

    // Simulation des déplacements et appel à dump()
    for (int i = 0; i < 10; ++i) {
        std::cout << "Itération: " << i + 1 << std::endl;

        // Déplacer les robots et afficher leurs informations
        r1->run(1.0);  // Avancer d'un pas
        r1->dump();    // Afficher l'état du robot

        r2->run(1.0);  // Avancer d'un pas
        r2->dump();    // Afficher l'état du robot

        // Vous pouvez ajouter une pause si nécessaire
        // std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    // Nettoyage des objets alloués
    delete obstacle1;
    delete obstacle2;
    delete obstacle3;
    delete obstacle4;
    delete r1;
    delete r2;

    return 0;
}
