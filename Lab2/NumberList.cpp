#include "NumberList.h"

void NumberList::Init()
{
    count = 0;
}
bool NumberList::Add(int x)
{
    if (count < 10)
    {
        numbers[count] = x;
        count++;
        return true;
    }
    return false;
}
void NumberList::Sort()
{
    for(int i=1; i<count; i++)
    {
        for(int j=i; j<count; j++)
        {
            if(numbers[j] < numbers[j-1])
            {
                int aux = numbers[j];
                numbers[j] = numbers[j-1];
                numbers[j-1] = aux;
            }
        }
    }
}
void NumberList::Print()
{
    for(int i=0; i<count; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;
}