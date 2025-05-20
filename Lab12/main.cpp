//
// Created by Ionut Meraru on 20.05.2025.
//

#include "ZOO.cpp"

#include <iostream>

#include "Animal.h"


int main() {
    Zoo zoo;

    Animal* leu1 = new Leu("Simba", 5);
    Animal* elefant1 = new Elefant("Dumbo", 10);
    Animal* leu2 = new Leu("Nala", 3);

    ((zoo(leu1))(elefant1))(leu2);


    zoo.afiseazaAnimale();


    std::cout << "\nCreștem vârsta fiecărui animal cu ++ (prefix)...\n";
    for (auto a : zoo.getAnimale()) {
        ++(*a);
        std::cout << (*a)() << std::endl;
    }


    std::cout << "\n Testare postfix ++ (afișează vârsta veche):\n";
    for (auto a : zoo.getAnimale()) {
        Animal vechi = (*a)++;
        std::cout << "Înainte: " << vechi() << " | După: " << (*a)() << std::endl;
    }

    return 0;
}
