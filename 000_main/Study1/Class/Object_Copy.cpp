#include <iostream>
using namespace std;

class Test{
    int value;

    public :
        void set_value(int n) { value = n; }
        int get_value() {return value; }
};

int main()
{
    Test T1, T2;

    T1.set_value(5); // Input only to Class T1.
    T2 = T1; // Copy Class.

    cout << T1.get_value() << endl; // print 5
    cout << T2.get_value() << endl; // print 5 

    return 0;
}