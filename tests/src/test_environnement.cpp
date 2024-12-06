#include <gtest/gtest.h>
#include <walle-lib/environnement.hpp>

// Validates the behavior of the constructors
TEST(Environnment, test_constructor) {
    // Creates an environment of size 200m x 200m
    Environment e{-100,+100,-100,100};

    EXPECT_NEAR(e.left(), -100, 0.00001);
    EXPECT_NEAR(e.right(), 100, 0.00001);
    EXPECT_NEAR(e.bottom(), -100, 0.00001);
    EXPECT_NEAR(e.top(), 100, 0.00001);
}

TEST(Environnment, test_constructor_invalid_behavior) {
    // Creates an environment of size 200m x 200m but with wrong
    // values.
    Environment e{100,-100,-100,100};

    EXPECT_GT(e.right(), e.left());
    EXPECT_GT(e.top(), e.bottom());
}

TEST(Environnment, test_add_element) {
    // Creates an environment of size 200m x 200m but with wrong values.
    Environment e{100,-100,-100,100};

    EXPECT_EQ(e.get_elements().size(), 0);
    e.add_element(new Element(&e));
    e.add_element(new Element(&e));
    EXPECT_EQ(e.get_elements().size(), 2);

    // Vérification des identifiants des elements
    std::vector<Element *> elements = e.get_elements();
    EXPECT_NE(elements[0]->get_id_e(), elements[1]->get_id_e()); // Les identifiants doivent être uniques
    EXPECT_EQ(elements[0]->get_id_e(), 0);                  // Premier element, ID = 0
    EXPECT_EQ(elements[1]->get_id_e(), 1);                  // Deuxième element, ID = 1

    // Suppression des robots
    for (Element* element : elements) {
        e.remove_element(element);
        delete element; // Libération de mémoire
    }
    EXPECT_EQ(e.get_objects().size(), 0);

    //EXPECT_TRUE(false) << "Uncomment the line before";
}

TEST(RobotTest, TestMoveBasic) {
    Environment e{100, -100, -100, 100};  // Crée un environnement de taille 200m x 200m

    // Ajout de robots directement
    Robot* r1 = new Robot(&e);  // Crée un robot dans cet environnement
    Robot* r2 = new Robot(&e);  // Crée un deuxième robot
    e.add_element(r1);  // Ajoute le premier robot
    e.add_element(r2);  // Ajoute le deuxième robot

    // Initialiser le premier robot pour qu'il se déplace sur une trajectoire spécifique
    r1->set_theta(M_PI / 4);  // Orientation à 45 degrés (en radians)
    r1->set_speed(1.0);  // Définit la vitesse linéaire à 1 m/s

    r1->run(1.0);  // Fait avancer le robot pendant 1 seconde

    // Appeler dump() pour vérifier les informations des robots
    std::cout << "État des robots après mouvement :" << std::endl;
    r1->dump();  // Affiche les informations du premier robot
    r2->dump();  // Affiche les informations du deuxième robot

    // Vérifications des positions
    EXPECT_NEAR(r1->get_position_x(), 0.70711, 0.00001);  // Vérifie la position X (cos(π/4) * 1)
    EXPECT_NEAR(r1->get_position_y(), 0.70711, 0.00001);  // Vérifie la position Y (sin(π/4) * 1)
    EXPECT_EQ(r2->get_position_x(), 0);  // Vérifie que le second robot n'a pas bougé
    EXPECT_EQ(r2->get_position_y(), 0);  // Vérifie que le second robot n'a pas bougé

    // Suppression des robots après le test
    e.remove_robot(r1);
    e.remove_robot(r2);
    delete r1;
    delete r2;
}

TEST(RobotTest, TestAvoidCollisionWithAngleAdjustments) {
    Environment e{100, -100, -100, 100};  // Crée un environnement de taille 200m x 200m

    // Crée un robot dans cet environnement
    Robot* r = new Robot(&e);
    e.add_element(r);

    // Crée un obstacle positionné sur le chemin du robot
    Element* obstacle1 = new Element(&e);
    obstacle1->set_x_element(2.0);
    obstacle1->set_y_element(0.0);
    obstacle1->set_width_element(1.0);
    obstacle1->set_length_element(1.0);
    e.add_element(obstacle1);

    // Configure la vitesse et l'angle initial du robot
    r->set_speed(1.0);  // 1 m/s
    r->set_theta(0);    // Avancer droit devant

    // Simule le déplacement pour 2 secondes (1 m/s, donc collision attendue après 2 m)
    r->run(1.0);  // Premier mouvement
    EXPECT_NEAR(r->get_position_x(), 1.0, 0.0001);  // Robot avance de 1 m sans collision
    EXPECT_NEAR(r->get_position_y(), 0.0, 0.0001);

    r->run(1.0);  // Deuxième mouvement, collision attendue avec l'obstacle

    EXPECT_NEAR(r->get_position_x(), 1.0, 0.0001);  // Robot atteint l'obstacle
    EXPECT_NEAR(r->get_position_y(), 1.0, 0.0001);  // Robot atteint l'obstacle

    r->run(1.0);
    EXPECT_NEAR(r->get_position_x(), 1.0, 0.0001);  // Robot évite l'obstacle
    EXPECT_NEAR(r->get_position_y(), 2.0, 0.0001);  // Robot évite l'obstacle

    r->run(1.0);
    EXPECT_NEAR(r->get_position_x(), 2.0, 0.0001);  // Robot évite l'obstacle
    EXPECT_NEAR(r->get_position_y(), 2.0, 0.0001);  // Robot évite l'obstacle

    // Nettoyage
    delete obstacle1;
    delete r;
}
