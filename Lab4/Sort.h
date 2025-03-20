#pragma once
#include <iostream>
#include <string>
class Sort
{
    int ElementsCount;
    int v[101];
public:
    Sort(int NumElements, int MaxInterval, int MinInterval);
    Sort();
    Sort(int v[101], int NumElements);
    Sort(int count, ...);
    Sort(std::string list);
    ~Sort();
    void InsertSort(bool ascendent=false);
    void QuickSort(bool ascendent=false);
    void BubbleSort(bool ascendent=false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};
