//
// Created by PaulQUIQUEMPOIS on 29/11/2024.
//

#pragma once

#include <string>

class environnement {
public:
void set_length();
void set_width();
void set_typeOfLand(std::string typeOfLand);

    double get_length() const;
    double get_width() const;


void automatcalySetSeedPlant(); // fonction void qui me permet de placer des graines de manière efficace tout les 5 mètres en évitant les obstacles

private:
    double length{0};
    double width{0};
    std::string typeOfLand{" "};
};