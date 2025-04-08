#pragma once
#include "Car.h"
#ifndef RANGEROVER_H
#define RANGEROVER_H

class RangeRover : public Car
{
public:
    RangeRover();
    double RaceTime(int circuitLenght, Weather weather) override;
    bool CanFinish(int circuitLenght) override;
    const char* getName() override;

};

#endif
