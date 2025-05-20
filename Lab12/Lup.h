//
// Created by Ionut Meraru on 20.05.2025.
//

#ifndef LUP_H
#define LUP_H

#include "Animal.h"

class Lup : public Animal
{
public:
    Lup();
    Lup(const std::string& nume, int varsta);
    std::string sunet() override;
    ~Lup();
    int getVarsta() override;
    std::string getNume() override;
};



#endif //LUP_H
