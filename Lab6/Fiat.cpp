#include "Fiat.h"

Fiat::Fiat() : Car(30, 5, 45, 30, 60){};

double Fiat::RaceTime(int circuitLenght, Weather weather) {
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
bool Fiat::CanFinish(int circuitLenght)
{
    double FuelNeeded = circuitLenght/AvgSpeedRain * 100.0;
    if (FuelNeeded <= FuelCapacity)
    {
        return true;
    }
    else return false;
}

const char* Fiat::getName()
{
    return "Fiat";
}



