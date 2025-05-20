//
// Created by Ionut Meraru on 20.05.2025.
//
#include "Animal.h"

Animal::Animal(const std::string& nume, int varsta) : nume(nume), varsta(varsta) {}

Animal::~Animal() {}

std::string Animal::getNume() {
    return nume;
}

int Animal::getVarsta() {
    return varsta;
}

Animal& Animal::operator++() {
    varsta++;
    return *this;
}

Animal Animal::operator++(int) {
    Animal copie = *this;
    varsta++;
    return copie;
}

std::string Animal::operator()() {
    return "Nume: " + nume + ", Varsta: " + std::to_string(varsta) + ", Sunet: " + sunet();
}