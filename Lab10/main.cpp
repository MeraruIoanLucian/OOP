#include <iostream>
#include "Array.h"

int main() {

    class IntComparator : public Compare {
    public:

        virtual int CompareElements(void* e1, void* e2) override {
            int* p1 = (int*)e1;
            int* p2 = (int*)e2;

            return *p1 - *p2;
        }
    };


    //Capacitate invalida
    try {
        Array<int> arr1(-10);
    } catch (const ArrayExceptions::InvalidCapacityException& e) {
        std::cout << "  Exception caught: " << e.what() << std::endl;
    }

    // Out of bounds cu index
    Array<int> arr2(3);
    arr2 += 10;
    arr2 += 20;
    try {
        int value = arr2[5];
    } catch (const ArrayExceptions::OutOfBoundsException& e) {
        std::cout << "  Exception caught: " << e.what() << std::endl;
    }

    // Out of bounds cu insert
    Array<int> arr3(5);
    arr3 += 30;
    arr3 += 40;
    try {
        arr3.Insert(-2, 50);
    } catch (const ArrayExceptions::OutOfBoundsException& e) {
        std::cout << "  Exception caught: " << e.what() << std::endl;
    }

    // Out of bounds cu delete
    Array<int> arr4(3);
    arr4 += 60;
    arr4 += 70;
    try {
        arr4.Delete(10);
    } catch (const ArrayExceptions::OutOfBoundsException& e) {
        std::cout << "  Exception caught: " << e.what() << std::endl;
    }

    // Empty Array cu Binary
    Array<int> arr5(5);
    try {
        int pos = arr5.BinarySearch(100);
    } catch (const ArrayExceptions::EmptyArrayException& e) {
        std::cout << "  Exception caught: " << e.what() << std::endl;
    }

    Array<int> arr6(5);
    try
    {
        arr6 +=10;
        arr6+= 11;
        arr6 += 9;

        IntComparator comparator;
        arr6.Sort(&comparator);
        for (int i=0; i<5; i++)
        {
            std::cout << arr6[i] << endl;
        }

    }
    catch (const std::exception& e){
        std::cout << "  Exception caught: " << e.what() << std::endl;
    }


    return 0;
}