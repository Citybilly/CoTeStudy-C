#include <iostream>
#include "Point.h"
using namespace std;

Point::Point(const int &xpos, const int &ypos)
{
    x = xpos;
    y = ypos;
}

int Point::GetX() const //  const 함수
{
    return x;
}

int Point::GetY() const // const 함수
{
    return y;
}

bool Point::SetX(int xpos)
{
    if(0>xpos || xpos>100)
    {
        cout << "벗어난 범위의 값 전달" << endl;
        return false;
    }
    x=xpos;
    return true;
}

bool Point::SetY(int ypos)
{
    if(0>ypos || ypos>100)
    {
        cout << "벗어난 범위의 값 전달" << endl;
        return false;
    }
    y=ypos;
    return true;
}