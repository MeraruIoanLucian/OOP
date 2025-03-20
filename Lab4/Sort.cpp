#include "Sort.h"

Sort::Sort(int NumElements, int MaxInterval, int MinInterval)
{
    ElementsCount = NumElements;
    for (int i = 0; i < ElementsCount; i++)
    {
        v[i] = rand() % (MaxInterval - MinInterval) + MinInterval;
    }
}
Sort::Sort()
{
    ElementsCount = 0;
}
Sort::Sort(int arr[101], int NumElements)
{
    ElementsCount = NumElements;
    for (int i = 0; i < ElementsCount; i++)
    {
        v[i] = arr[i];
    }
}
Sort::Sort(int count, ...)
{
    ElementsCount = count;
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++)
    {
        v[i] = va_arg(args, int);
    }
    va_end(args);
}
Sort::Sort(std::string list)
{
    ElementsCount = 0;
    std::string delimiter = ",";
    size_t pos = 0;
    std::string token;
    while ((pos = list.find(delimiter)) != std::string::npos)
    {
        token = list.substr(0, pos);
        v[ElementsCount++] = std::stoi(token);
        list.erase(0, pos + delimiter.length());
    }
    //v[ElementsCount++] = std::stoi(list);
}
Sort::~Sort()
{
}
void Sort::InsertSort(bool ascendent)
{
    for (int i = 1; i < ElementsCount; i++)
    {
        int key = v[i];
        int j = i - 1;
        if (ascendent)
        {
            while (j >= 0 && v[j] > key)
            {
                v[j + 1] = v[j];
                j = j - 1;
            }
        }
        else
        {
            while (j >= 0 && v[j] < key)
            {
                v[j + 1] = v[j];
                j = j - 1;
            }
        }
        v[j + 1] = key;
    }
}
void Sort::BubbleSort(bool ascendent)
{
    for (int i = 0; i < ElementsCount - 1; i++)
    {
        for (int j = 0; j < ElementsCount - i - 1; j++)
        {
            if (ascendent)
            {
                if (v[j] > v[j + 1])
                {
                    int temp = v[j];
                    v[j] = v[j + 1];
                    v[j + 1] = temp;
                }
            }
            else
            {
                if (v[j] < v[j + 1])
                {
                    int temp = v[j];
                    v[j] = v[j + 1];
                    v[j + 1] = temp;
                }
            }
        }
    }
}

void Sort::QuickSort(bool ascendent)
{
    int stack[101];
    int top = -1;
    stack[++top] = 0;
    stack[++top] = ElementsCount - 1;

    while (top >= 0)
    {
        int high = stack[top--];
        int low = stack[top--];

        int pivot = v[high];
        int i = low - 1;
        for (int j = low; j < high; j++)
        {
            if (ascendent ? (v[j] < pivot) : (v[j] > pivot))
            {
                i++;
                int temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
        int p = i + 1;
        int temp = v[p];
        v[p] = v[high];
        v[high] = temp;

        if (p - 1 > low)
        {
            stack[++top] = low;
            stack[++top] = p - 1;
        }
        if (p + 1 < high)
        {
            stack[++top] = p + 1;
            stack[++top] = high;
        }
    }
}
int Sort::GetElementsCount()
{
    return ElementsCount;
}
int Sort::GetElementFromIndex(int index)
{
    return v[index];
}
void Sort::Print()
{
    for (int i = 0; i < ElementsCount; i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}