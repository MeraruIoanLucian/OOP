#pragma once

#ifndef CAR_H
#define CAR_H
#include "Weather.h"

class Car
{
public:
    int FuelCapacity;
    int FuelConsumption;
    int AvgSpeedRain;
    int AvgSpeedSnow;
    int AvgSpeedSunny;
    Car(int FuelCap, int FuelCons, int AvgSpdRain, int AvgSpdSnow, int AvgSpdSunny):FuelCapacity(FuelCap), FuelConsumption(FuelCons), AvgSpeedRain(AvgSpdRain), AvgSpeedSnow(AvgSpdSnow), AvgSpeedSunny(AvgSpdSunny){};

    virtual double RaceTime(int circuitLenght, Weather weather) = 0;
    virtual bool CanFinish(int circuitLenght) = 0;
    virtual const char* getName() = 0;
};



#endif //CAR_H
