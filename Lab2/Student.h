#pragma once
#include <iostream>
using namespace std;

class Student
{
    string name;
    float grade_maths;
    float grade_english;
    float grade_history;
public:
    float get_math_grade();
    float get_english_grade();
    float get_history_grade();
    float get_average();
    string get_name();
    void set_name(string name);
    void set_math_grade(int grade);
    void set_english_grade(int grade);
    void set_history_grade(int grade);
};