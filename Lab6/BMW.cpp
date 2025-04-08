#include "BMW.h"

BMW::BMW() : Car(60, 15, 70, 50, 120){};

double BMW::RaceTime(int circuitLenght, Weather weather) {
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
    int RaceTime;
    if (FuelNeeded > FuelCapacity)
    {
        return RaceTime = -1;
    }
    RaceTime = circuitLenght / speed;
    return RaceTime;
}
bool BMW::CanFinish(int circuitLenght)
{
    double FuelNeeded = circuitLenght/AvgSpeedRain * 100.0;
    if (FuelNeeded <= FuelCapacity)
    {
        return true;
    }
    else return false;
}

const char* BMW::getName()
{
    return "BMW";
}



