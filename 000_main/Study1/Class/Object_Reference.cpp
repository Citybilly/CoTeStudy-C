#include <iostream>

using namespace std;

class Test{

    int value;
public:
    void set_value(int n) { value = n;}
    int  get_value() { return value; }
    int  get_square(Test &k) { return k.get_value()*k.get_value();} // Look at (Test &k) input as Reference
};

int main()
{
    Test t;

    t.set_value(7);
    cout << t.get_value() << endl;
    cout << t.get_square(t) << endl;

    return 0;
}