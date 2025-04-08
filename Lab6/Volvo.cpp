#include "Volvo.h"

Volvo::Volvo() : Car(60, 6, 60, 40, 80){};

double Volvo::RaceTime(int circuitLenght, Weather weather) {
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
bool Volvo::CanFinish(int circuitLenght)
{
    double FuelNeeded = circuitLenght/AvgSpeedRain * 100.0;
    if (FuelNeeded <= FuelCapacity)
    {
        return true;
    }
    else return false;
}

const char* Volvo::getName()
{
    return "Volvo";
}



