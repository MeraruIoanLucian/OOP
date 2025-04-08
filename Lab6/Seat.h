#pragma once
#include "Car.h"
#ifndef SEAT_H
#define SEAT_H

class Seat : public Car
{
public:
    Seat();
    double RaceTime(int circuitLenght, Weather weather) override;
    bool CanFinish(int circuitLenght) override;
    const char* getName() override;

};

#endif
