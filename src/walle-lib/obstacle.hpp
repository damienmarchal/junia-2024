//
// Created by PaulQUIQUEMPOIS on 29/11/2024.
//
#pragma once
#include <cmath>
#include <string>
//#include "environnement.hpp"

class Environment;  // Déclaration anticipée d'Environment

class Element {
public:
    Element(Environment* e = nullptr) : environment(e), id_e(next_id_e++) {}
    virtual ~Element() = default;

    int get_id_e() const { return id_e; }

    void set_length_element(double length_elements);
    void set_width_element(double width_elements);
    void set_x_element(double x_elements);
    void set_y_element(double y_elements);

    double get_length_element();
    double get_width_element();
    double get_x_element();
    double get_y_element();


private:

    int id_e;  // Identifiant unique pour chaque element
    static int next_id_e;  // Prochaine valeur d'identifiant à utiliser

    double length_element{0};
    double width_element{0};
    double x_element{0};
    double y_element{0};

protected:
    Environment* environment {nullptr}; //pointeur

};