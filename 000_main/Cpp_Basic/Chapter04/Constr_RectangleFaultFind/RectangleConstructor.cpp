#include <iostream>
#include "Point.h"
#include "Rectangle.h"
using namespace std;

int main(void)
{
    Rectangle rec(1, 1, 5, 5);
    rec.ShowRecInfo();
    return 0;
}

// compile command : g++ -std=c++14 RectangleConstructor.cpp Point.cpp Rectangle.cpp -o main.out
// execute command : ./main.out