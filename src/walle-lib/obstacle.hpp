//
// Created by PaulQUIQUEMPOIS on 29/11/2024.
//

#pragma once

#include "environnement.hpp"

class obstacle : public environnement {
public:
    void createObstacleRand(double numberOfObstacle);
    void setObstacle(double lengthObstacle, double widthObstacle, double xObstacle, double yObstacle);
    void setBase(double xBase, double yBase);
private:
    double lengthObstacle{0};
    double widthObstacle{0};
    double xObstacle{0};
    double yObstacle{0};
    double xBase{0};
    double yBase{0};
    double lengthBase{5};
    double widthBase{2};
};