#include "Circuit.h"
#include <iostream>
using namespace std;

Circuit::Circuit() : length(0), raceweather(Sunny), carCount(0) {
    for (int i = 0; i < 100; i++) {
        cars[i] = nullptr;
    }
}

void Circuit::SetLength(int len) {
    this -> length = len;
}

void Circuit::SetWeather(Weather w) {
    this -> raceweather = w;
}

void Circuit::AddCar(Car* car) {
    if (carCount < 100)
        cars[carCount++] = car;
}

void Circuit::Race() {}

void Circuit::ShowFinalRanks() {
    for (int i = 0; i < carCount - 1; i++) {
        for (int j = 0; j < carCount - i - 1; j++) {
            int t1 = cars[j]->RaceTime(length, raceweather);
            int t2 = cars[j+1]->RaceTime(length, raceweather);
            if (t1 > t2) {
                Car* temp = cars[j];
                cars[j] = cars[j+1];
                cars[j+1] = temp;
            }
        }
    }
    int rank = 1;
    for (int i = 0; i < carCount; i++) {
        int t = cars[i]->RaceTime(length, raceweather);
        if (t >= 0) {
            cout << cars[i]->getName() << " is number " << rank << " with time: " << t << " hours" << endl;
            rank++;
        }
    }
}

void Circuit::ShowWhoDidNotFinish() {
    cout << "Cars that did not finish:" << endl;
    for (int i = 0; i < carCount; i++) {
        if (cars[i]->RaceTime(length, raceweather) < 0)
            cout << cars[i]->getName() << endl;
    }
}