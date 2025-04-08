#pragma once
#include "Car.h"
#ifndef VOLVO_H
#define VOLVO_H

class Volvo : public Car
{
public:
    Volvo();
    double RaceTime(int circuitLenght, Weather weather) override;
    bool CanFinish(int circuitLenght) override;
    const char* getName() override;

};

#endif
