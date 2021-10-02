#include <iostream>

using namespace std;

class A
{
public:
    A(){cout <<"A\n";} // Default Constructor
};

class B
{
private:
    A m_a; // B contains A as a member variable
public:
    B(){cout <<"B\n";} // Default Constructor
};

int main()
{
    B b;
    return 0;
}