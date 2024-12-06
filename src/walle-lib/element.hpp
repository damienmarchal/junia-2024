#pragma once

#include <cmath>
#include <string>

#include "environment.hpp"

/// Element de l'environnement
class Element
{
public:
    Element(Environment *e) : environment(e) {};

    void set_position(double x, double y);

    double get_x() { return m_x; }
    double get_y() { return m_y; }

    std::string get_type() const { return m_type; }
    void set_type(const std::string &type) { m_type = type; }   

    double get_size() const { return m_size; }
    void set_size(double size) { m_size = size; }

private:
    double m_x{0};
    double m_y{0};
    std::string m_type;
    double m_size{0};

    // permet d'accéder à l'environnement
    Environment *environment{nullptr};

};
