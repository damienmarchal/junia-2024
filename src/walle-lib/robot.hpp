#ifndef ROBOT_HPP
#define ROBOT_HPP

class Robot
{
public:
    void avancer(double vitesse);
    void tourner(double angle);
    void stop();

    double get_x();
    double get_y();

private:
    double x;     // position x
    double y;     // position y
    double theta; // angle en radians
};

#endif