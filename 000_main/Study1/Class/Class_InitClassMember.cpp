#include  <iostream>

using namespace std;

class A
{
public:
    A(int x){std::cout << "A " << x << "\n"; }
};

class B
{
private:
    A m_a;
public :
    B(int y):m_a(y-1) // Call A(int) constructor to initialize member m_a
    {
        std::cout << "B " << y << "\n";
    }
};

int main()
{
    B b(5);
    return 0;
}