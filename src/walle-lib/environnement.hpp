#pragma once 
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include "Plantation.hpp"
#include "Element.hpp"

class Robot;

class Environment
{
protected:
    // liste de zones à planter obstacles et autres grace aux coordonnées
    // Pour les plantations il faudrait savoir l'état de la plantation pour savoir quel robot utiliser
    std::map<std::string, Element*> elements; //map d'éléments
    std::map<std::string, Robot*> robots; //liste de robots
    double m_left;
    double m_right;
    double m_bottom;
    double m_top;
public:
    Environment(double left, double right, double bottom, double top): m_left(left), m_right(right), m_bottom(bottom), m_top(top) {};


    double left() const { return m_left; }
    double right() const { return m_right; }
    double bottom() const { return m_bottom; }
    double top() { return m_top; }
    void add_element(const std::string name, Element* e);
    void add_robot(const std::string name, Robot* r);
    int get_nbre_elements();
    int get_nbre_robots();
    Element* get_element(std::string name);
    Robot* get_robot(std::string name);
    void remove_element(std::string name);
    void remove_robot(std::string name);
    // fonction pour filtrer les éléments
    template <typename T>
    std::map<std::string, T*> filter_by_type() {
        static_assert(std::is_base_of<Element, T>::value, 
                    "T must inherit from Element");
        std::map<std::string, T*> result;

        for (auto& [name, element] : elements) {
            T* casted = dynamic_cast<T*>(element);
            if (casted) {
                result[name] = casted;
            }
        }

        return result;
    }
};
