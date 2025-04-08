#include "Seat.h"

Seat::Seat() : Car(60, 12, 40, 30, 70){};

double Seat::RaceTime(int circuitLenght, Weather weather) {
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
bool Seat::CanFinish(int circuitLenght)
{
    double FuelNeeded = circuitLenght/AvgSpeedRain * 100.0;
    if (FuelNeeded <= FuelCapacity)
    {
        return true;
    }
    else return false;
}

const char* Seat::getName()
{
    return "Seat";
}



