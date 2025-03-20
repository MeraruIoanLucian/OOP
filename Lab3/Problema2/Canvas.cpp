#include "Canvas.h"

Canvas::Canvas(int width, int height)
{
    this->width = width;
    this->height = height;
    Clear();
}
void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            if ((i - x) * (i - x) + (j - y) * (j - y) == ray * ray)
                canvas[i][j] = ch;
}
void Canvas::FillCircle(int x, int y, int ray, char ch)
{
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            if ((i - x) * (i - x) + (j - y) * (j - y) <= ray * ray)
                canvas[i][j] = ch;
}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
    for (int i = top; i <= bottom; i++)
        for (int j = left; j <= right; j++)
            if (i == top || i == bottom || j == left || j == right)
                canvas[i][j] = ch;
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
    for (int i = top; i <= bottom; i++)
        for (int j = left; j <= right; j++)
            canvas[i][j] = ch;
}
void Canvas::SetPoint(int x, int y, char ch)
{
    canvas[x][y] = ch;
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    if (dx == 0)
    {
        for (int i = y1; i <= y2; i++)
            canvas[x1][i] = ch;
    }
    else
    {
        for (int i = x1; i <= x2; i++)
        {
            int j = y1 + dy * (i - x1) / dx;
            canvas[i][j] = ch;
        }
    }
}
void Canvas::Print()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            std::cout << canvas[i][j];
        std::cout << std::endl;
    }
}
void Canvas::Clear()
{
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            canvas[i][j] = ' ';
}


