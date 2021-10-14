#include <iostream>
using namespace std;

class Something
{
private:
    const int m_value;

public:
    Something():m_value {5}
    {
    }
};

class Smthing_array
{
private :
    const int m_array[5];

public:
    Something_array():m_array {} // zero the member array
    {
    }
};

int main()
{
    Something somthing;
//    cout << something.m_value << endl;
    return 0;
}