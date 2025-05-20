//
// Created by Ionut Meraru on 20.05.2025.
//

#ifndef ZOO_H
#define ZOO_H

#include "Animal.h"
#include "Lup.h"
#include "Oaie.h"
#include <iostream>

class Zoo
{
public:
    Animal* Animale[3];
    int nrAnimale;
    void afiseazaAnimale();
    std::string getAnimale();
    Zoo();
    Zoo& operator()(Animal* animal);
    ~Zoo();

};

#endif //ZOO_H
