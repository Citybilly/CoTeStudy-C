#include <iostream>
using namespace std;

class Foo
{
public:
    int m_x;
    int m_y;
};

int main()
{
    Foo foo1 = {4,5}; // initialization list
    Foo foo2 {6,7}; // uniform initialization (C++11) 

    return 0;    
}