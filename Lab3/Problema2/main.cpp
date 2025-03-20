#include "Canvas.cpp"
#include <unistd.h>

int main()
{
    Canvas c(20, 20);
    c.DrawCircle(10, 10, 5, '*');
    c.Print();
    sleep(3);
    c.Clear();
    c.FillCircle(10, 10, 5, '*');
    c.Print();
    sleep(3);
    c.Clear();
    c.DrawRect(5, 5, 15, 15, '*');
    c.Print();
    sleep(3);
    c.Clear();
    c.FillRect(5, 5, 15, 15, '*');
    c.Print();
    sleep(3);
    c.Clear();
    c.DrawLine(0, 0, 20, 20, '*');
    c.Print();
    return 0;
}