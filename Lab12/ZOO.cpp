//
// Created by Ionut Meraru on 20.05.2025.
//

#include "ZOO.h"

Zoo::Zoo(){};

Zoo&::operator ()(Animal* animal)
{
    Animale[nrAnimale++] = animal;
    return *this;
}
