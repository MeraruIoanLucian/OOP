//
// Created by Ionut Meraru on 20.05.2025.
//

#include "Lup.h"

Lup::Lup() : Animal("Wolfie", 6){};

Lup::Lup(const std::string& nume, int varsta) : Animal(nume, varsta) {};

std::string Lup::sunet()
{
    return "AUUUUUUU";
}
std::string Lup::getNume()
{
    return nume;
}