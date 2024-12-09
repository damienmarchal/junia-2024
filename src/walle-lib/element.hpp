#pragma once

class Environment;

/// Element de l'environnement
class Element
{
public:
    Element(Environment *e = nullptr);
    Element(Environment *e, double x, double y);

    void set_position(double x, double y);

    double get_x() const { return m_x; }
    double get_y() const { return m_y; }


    double get_size() const { return m_size; }
    void set_size(double size) { m_size = size; }

protected:
    double m_x{0};
    double m_y{0};
    double m_size{0}; // taille de l'élément (diamètre pour un cercle)

    // permet d'accéder à l'environnement
    Environment *environment{nullptr};

};
