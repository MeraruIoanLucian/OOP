#include "RangeRover.h"

RangeRover::RangeRover() : Car(60, 15, 80, 60, 100){};

double RangeRover::RaceTime(int circuitLenght, Weather weather) {
    int speed;
    if (weather == Rain)
    {
        speed = AvgSpeedRain;
    }
    else if (weather == Snow)
    {
        speed = AvgSpeedSnow;
    }
    else
    {
        speed = AvgSpeedSunny;
    }
    int FuelNeeded = (circuitLenght/100)*FuelConsumption;
    if (FuelNeeded > FuelCapacity)
    {
        return false;
    }
    int RaceTime = circuitLenght / speed;
    return RaceTime;
}
bool RangeRover::CanFinish(int circuitLenght)
{
    double FuelNeeded = circuitLenght/AvgSpeedRain * 100.0;
    if (FuelNeeded <= FuelCapacity)
    {
        return true;
    }
    else return false;
}

const char* RangeRover::getName()
{
    return "RangeRover";
}



