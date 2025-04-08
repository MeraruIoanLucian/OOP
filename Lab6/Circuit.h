#pragma once
#ifndef CIRCUIT_H
#define CIRCUIT_H

#include "Car.h"
#include "Weather.h"
#include <iostream>
#include "Fiat.cpp"
#include "Seat.cpp"
#include "Volvo.cpp"
#include "RangeRover.cpp"
#include "BMW.cpp"

class Circuit {
    int length;
    Weather raceweather;
    Car* cars[100];
    int carCount;
public:
    Circuit();
    void SetLength(int len);
    void SetWeather(Weather w);
    void AddCar(Car* car);
    void Race();
    void ShowFinalRanks();
    void ShowWhoDidNotFinish();
};

#endif