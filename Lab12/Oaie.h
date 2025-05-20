//
// Created by Ionut Meraru on 20.05.2025.
//
#include "Animal.h"
#ifndef OAIE_H
#define OAIE_H

class Oaie : public Animal
{
public:
    Oaie();
    Oaie(const std::string& nume, int varsta);
    std::string sunet() override;
    ~Oaie();
    int getVarsta() override;
    std::string getNume() override;

};

#endif //OAIE_H
