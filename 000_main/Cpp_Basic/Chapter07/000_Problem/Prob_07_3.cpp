#include <iostream>
using namespace std;

class Rectangle
{
private:
    int x_axis;
    int y_axis;
public:
    Rectangle(int x, int y)
        : x_axis(x), y_axis(y)
    { }

    void ShowAreaInfo()
    {
        int retVal;
        retVal = (x_axis * y_axis);
        cout << "면적: " << retVal << endl;
    }
};

class Square : public Rectangle
{
public:
    Square(int z)
        : Rectangle(z,z)
    {  }
};

int main(void)
{
    Rectangle rec(4,3);
    rec.ShowAreaInfo();

    Square sqr(7);
    sqr.ShowAreaInfo();
    return 0;
}