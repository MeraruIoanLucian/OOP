#include "Student.h"
float Student::get_math_grade()
{
    return grade_maths;
}
float Student::get_english_grade()
{
    return grade_english;
}
float Student::get_history_grade()
{
    return grade_history;
}
float Student::get_average()
{
    return (grade_maths + grade_english + grade_history) / 3;
}
string Student::get_name()
{
    return name;
}
void Student::set_name(string name)
{
    this->name = name;
}
void Student::set_math_grade(int grade)
{
    if(grade < 0 || grade > 10)
    {
        cout << "Invalid grade" << endl;
        return;
    }
    grade_maths = grade;
}
void Student::set_english_grade(int grade)
{
    if(grade < 0 || grade > 10)
    {
        cout << "Invalid grade" << endl;
        return;
    }
    grade_english = grade;
}
void Student::set_history_grade(int grade)
{
    if(grade < 0 || grade > 10)
    {
        cout << "Invalid grade" << endl;
        return;
    }
    grade_history = grade;
}