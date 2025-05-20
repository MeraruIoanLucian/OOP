//
// Created by Ionut Meraru on 20.05.2025.
//

#include "Oaie.h"

Oaie::Oaie() : Animal("Betty", 4){};

Oaie::~Oaie() = default;

std::string Oaie::sunet()
{
    return "Behehehehehehe";
}

std::string Oaie::getNume()
{
    return nume;
}
int Oaie::getVarsta()
{
    return varsta;
}
