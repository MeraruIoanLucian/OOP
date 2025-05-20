#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal {
protected:
    std::string nume;
    int varsta;
public:
    Animal(const std::string& nume, int varsta);
    virtual ~Animal();
    virtual std::string getNume();
    virtual int getVarsta();
    virtual std::string sunet() = 0;
    Animal& operator++();
    Animal operator++(int);
    std::string operator()();
};

#endif // ANIMAL_H
