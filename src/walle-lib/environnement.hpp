#pragma once

#include <string>
#include <stdexcept>
#include <vector>
#include "obstacle.hpp"
#include "robot.hpp"

/*
class Element;  // Déclaration anticipée d'Element
class Robot;    // Déclaration anticipée de Robot
*/
class Environment {
public:
    Environment() = default;
    Environment(double left, double right, double bottom, double top)
            : left_{std::min(left, right)}, right_{std::max(left, right)},
              bottom_{std::min(bottom, top)}, top_{std::max(bottom, top)} {}

    void set_typeOfLand();
    void set_nbr_of_obstacle();
    void create_envi_rand();

    double left() const { return left_; }
    double right() const { return right_; }
    double bottom() const { return bottom_; }
    double top() const { return top_; }

    // Récupérer tous les éléments de l'environnement
    std::vector<Element *> get_elements() const;

    const std::vector<Robot *> & get_objects() const;

    // Ajouter un robot à l'environnement
    void add_robot(Element *robot);

    // Récupérer tous les robots (si nécessaire séparément des autres éléments)
    std::vector<Robot*> get_objects();


    void add_element(Element *element);

    void remove_robot(Robot* robot_to_remove);

    void remove_element(Element* element_to_remove);

private:
    std::string typeOfLand{" "};
    double nbr_of_obstacle{0};

    double left_{0};
    double right_{0};
    double bottom_{0};
    double top_{0};

    std::vector<Element*> elements;  // Vecteur pour stocker tous les éléments (y compris les robots)

};
