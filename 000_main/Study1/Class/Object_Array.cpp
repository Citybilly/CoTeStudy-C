#include<iostream>
#include <array>
using namespace std;

class Test{
    int value;
public:
    void set_value(int n) { value = n; }
    int get_value() { return value; }
};

int main()
{
    Test t[5];

    for(int i = 0; i < 5; i++)
    {
        t[i].set_value(i);
        cout << t[i].get_value() << endl;
    }

    array <Test, 5> T; // Define as std::array

    for(int i = 0; i < 5; i++)
    {
        T[i].set_value(i);
        cout << T[i].get_value() << endl;
    }

    return 0;

}