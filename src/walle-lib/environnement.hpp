#pragma once
#include <vector>
#include "vector2.hpp"
class Element;

class InvalidBoundariesEnvironmentException : public std::exception {
public:
    const char* what() const noexcept override;
};

class Environment
{
public:
    Environment(double left=-1, double right=-1,
                double top=-1, double bottom=-1);

    double left() const;
    double right() const;
    double top() const;
    double bottom() const;

    Vector2<double> center() const;

    const std::vector<Element*> get_elements() const;
    unsigned int get_elements_number() const;
    void add_element(Element* element);

private:
    double left_;
    double right_;
    double top_;
    double bottom_;
    std::vector<Element*> elements_;
};
