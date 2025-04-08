#pragma once
#include "Car.h"
#ifndef BMW_H
#define BMW_H

class BMW : public Car
{
    public:
    BMW();
    double RaceTime(int circuitLenght, Weather weather) override;
    bool CanFinish(int circuitLenght) override;
    const char* getName() override;

};

#endif //BMW_H
