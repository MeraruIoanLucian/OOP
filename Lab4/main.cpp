#include "Sort.cpp"

int main()
{
    Sort sRand(10, 1, 100);
    sRand.Print();
    sRand.InsertSort(true);
    sRand.Print();
    Sort sVar(5, 10, 40, 100, 70);
    sVar.Print();
    sVar.BubbleSort(true);
    sVar.Print();
    Sort sString("10,40,100,5,70");
    sString.Print();
    sString.QuickSort(true);
    sString.Print();
    int arr[101] = {9, 3, 6, 2, 8, 7};
    Sort sArr(arr, 6);
    sArr.Print();
    sArr.InsertSort(false);
    sArr.Print();
    return 0;
}