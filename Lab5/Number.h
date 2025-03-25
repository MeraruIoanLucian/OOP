#pragma once
#include <iostream>

using namespace std;

class Number {
    char* value;
    int base;
public:
    Number(const char* value, int base);
    Number(int n);
    ~Number();
    Number(const Number& n);
    Number(Number&& n);
    Number& operator=(const Number& n);
    Number& operator=(Number&& n);
    Number& operator=(const char *newValue);
    void Print();
    void SwitchBase(int newBase);
    int GetDigitsCount();
    int GetBase();
    friend Number operator+(Number const& n1, Number const& n2);
    friend Number operator-(Number const& n1, Number const& n2);
    Number& operator+=(const Number& n);
    Number& operator-=(const Number& n);
    const char& operator[](int);
    Number& operator--();
    Number operator--(int);
    bool operator>(const Number& n);
    bool operator<(const Number& n);
    bool operator>=(const Number& n);
    bool operator<=(const Number& n);
    bool operator==(const Number& n);
    bool operator!=(const Number& n);
};