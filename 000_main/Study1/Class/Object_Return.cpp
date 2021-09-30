#include <iostream>
using namespace std;

class Test{
    int value;

public:
    void setValue(int n) { value = n; }
    int getValue(){ return value; }
};

Test Object_compare(Test &t1, Test &t2){ // Object Reference, return type must be name  of class
    return t1.getValue() > t2.getValue() ? t1: t2;
}

int main()
{
    Test T1, T2;
    Test result;

    T1.setValue(2);
    T2.setValue(5);

    result = Object_compare(T1, T2);
    
    cout << result.getValue() << endl; // 
    return 0;
}