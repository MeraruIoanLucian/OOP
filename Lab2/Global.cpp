#include "Global.h"
string compare_name(Student s1, Student s2)
{
    if(s1.get_name() == s2.get_name())
        return 0;
    else if(s1.get_name() < s2.get_name())
        return s1.get_name();
    else
        return s2.get_name();
}
float compare_average(Student s1, Student s2)
{
    if(s1.get_average() == s2.get_average())
        return 0;
    else if(s1.get_average() < s2.get_average())
        return s2.get_average();
    else
        return s1.get_average();
}
float compare_math_grade(Student s1, Student s2)
{
    if(s1.get_math_grade() == s2.get_math_grade())
        return 0;
    else if(s1.get_math_grade() < s2.get_math_grade())
        return s2.get_math_grade();
    else
        return s1.get_math_grade();
}
float compare_english_grade(Student s1, Student s2)
{
    if(s1.get_english_grade() == s2.get_english_grade())
        return 0;
    else if(s1.get_english_grade() < s2.get_english_grade())
        return s2.get_english_grade();
    else
        return s1.get_english_grade();
}
float compare_history_grade(Student s1, Student s2)
{
    if(s1.get_history_grade() == s2.get_history_grade())
        return 0;
    else if(s1.get_history_grade() < s2.get_history_grade())
        return s2.get_history_grade();
    else
        return s1.get_history_grade();
}