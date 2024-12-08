#include "environnement.hpp"
#include "environnement.hpp"
#include "Robot.hpp"


void Environment::add_element(const std::string name, Element* e)
{
    if (elements.find(name) != elements.end()) {
        throw std::runtime_error("An element with this name already exists.");
    }
    elements[name] = e;
}

int Environment::get_nbre_elements()
{
    return elements.size();
}

Element* Environment::get_element(std::string name)
{
    auto it = elements.find(name);
        if (it != elements.end())
            return it->second;
        return nullptr;
}

void Environment::remove_element(std::string name)
{
    auto it = elements.find(name);
    if (it != elements.end()) {
        delete it->second; // Libérer la mémoire si nécessaire
        elements.erase(it);
    } else {
        throw std::runtime_error("Element not found.");
    }
}

void Environment::add_robot(const std::string name, Robot* r)
{
    if (robots.find(name) != robots.end()) {
        throw std::runtime_error("A robot with this name already exists.");
    }
    robots[name] = r;
}

int Environment::get_nbre_robots()
{
    return robots.size();
}

Robot* Environment::get_robot(std::string name)
{
    auto it = robots.find(name);
    if (it != robots.end())
        return it->second;
    return nullptr;
}

void Environment::remove_robot(std::string name)
{
    auto it = robots.find(name);
    if (it != robots.end()) {
        delete it->second; // Libérer la mémoire si nécessaire
        robots.erase(it);
    } else {
        throw std::runtime_error("Robot not found.");
    }
}