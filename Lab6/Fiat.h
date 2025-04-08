#pragma once
#include "Car.h"
#ifndef FIAT_H
#define FIAT_H

class Fiat : public Car
{
public:
    Fiat();
    double RaceTime(int circuitLenght, Weather weather) override;
    bool CanFinish(int circuitLenght) override;
    const char* getName() override;

};

#endif
