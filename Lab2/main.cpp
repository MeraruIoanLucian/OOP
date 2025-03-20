#include "Global.cpp"
#include <iostream>
using namespace std;

int main()
{
    Student s1, s2;
    s1.set_name("Andrei");
    s1.set_math_grade(9);
    s1.set_english_grade(8);
    s1.set_history_grade(7);
    s2.set_name("Ionutzu");
    s2.set_math_grade(10);
    s2.set_english_grade(9);
    s2.set_history_grade(8);
    cout << "Name: " << compare_name(s1, s2) << endl;
    cout << "Average (cel mai mare): " << compare_average(s1, s2) << endl;
    cout << "Math grade (cea mai mare): " << compare_math_grade(s1, s2) << endl;
    cout << "English grade (cea mai mare): " << compare_english_grade(s1, s2) << endl;
    cout << "History grade (cea mai mare): " << compare_history_grade(s1, s2) << endl;
    return 0;
}