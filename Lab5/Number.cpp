#include "Number.h"
#include <stdlib.h>

Number::Number(const char* value, int base) {
    this->value = new char[strlen(value)+1];
    strcpy(this->value, value);
    this->base = base;
}

Number::Number(int n) {
    this->value = new char[20];
    sprintf(this->value, "%d", n);
    this->base = 10;
}

Number::Number(const Number& n) {
    this->value = new char[strlen(n.value)+1];
    strcpy(this->value, n.value);
    this->base = n.base;
}

Number::Number(Number&& n) {
    this->value = n.value;
    this->base = n.base;
    n.value = nullptr;
    n.base = 0;
}

Number::~Number() {
    delete[] value;
}

Number& Number::operator=(const Number& n) {
    if (this != &n) {
        char* newValue = new char[strlen(n.value) + 1];
        strcpy(newValue, n.value);
        delete[] value;
        value = newValue;
        base = n.base;
    }
    return *this;
}

Number& Number::operator=(Number&& n) {
    if (this != &n) {
        delete[] value;
        value = n.value;
        base = n.base;
        n.value = nullptr;
        n.base = 0;
    }
    return *this;
}

Number& Number::operator=(const char* newValue) {
    delete[] value;
    value = new char[strlen(newValue) + 1];
    strcpy(value, newValue);
    return *this;
}

void Number::Print() {
    printf("%s\n", this->value);
}

void Number::SwitchBase(int newBase) {
    this->base = newBase;
    
}//todo trebuie refacut value

int Number::GetDigitsCount() {
    return strlen(this->value);
}

int Number::GetBase() {
    return this->base;
}

Number operator+(Number const &n1, Number const &n2) {
    int largerBase = (n1.base >= n2.base ? n1.base : n2.base);
    int result = atoi(n1.value) + atoi(n2.value); //todo duc amandoua in baza 10 si trebuie sa am 2 inturi pe care le adun si trec rez in baza noua
    char sumValue[20];
    sprintf(sumValue, "%d", result);
    Number sum(sumValue, largerBase);
    return sum;
}

Number operator-(Number const &n1, Number const &n2) {
    int largerBase = (n1.base >= n2.base ? n1.base : n2.base);
    int result = atoi(n1.value) - atoi(n2.value);
    char sumValue[100];
    sprintf(sumValue, "%d", result);
    Number sum(sumValue, largerBase);
    return sum;
}

Number& Number::operator+=(const Number& n) {
    *this = *this + n;
    return *this;
}

Number& Number::operator-=(const Number& n) {
    *this = *this - n;
    return *this;
}

const char& Number::operator[](int index) {
    if (index >= strlen(value))
        exit(0);
    return value[index];
}

Number& Number::operator--() {
    int length = GetDigitsCount();
    for (int i = 0; i < length - 1; i++)
        value[i] = value[i+1];
    value[length - 1] = '\0';
    return *this;
}

Number Number::operator--(int) {
    Number temp(*this);
    int length = GetDigitsCount();
    value[length - 1] = '\0';
    return temp;
}

bool Number::operator>(const Number& n) {
    return (atoi(this->value) > atoi(n.value));
}

bool Number::operator<(const Number& n) {
    return (atoi(this->value) < atoi(n.value));
}

bool Number::operator>=(const Number& n) {
    return (atoi(this->value) >= atoi(n.value));
}

bool Number::operator<=(const Number& n) {
    return (atoi(this->value) <= atoi(n.value));
}

bool Number::operator==(const Number& n) {
    return (atoi(this->value) == atoi(n.value));
}

bool Number::operator!=(const Number& n) {
    return (atoi(this->value) != atoi(n.value));
}