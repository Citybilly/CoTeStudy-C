#include <iostream>
using namespace std;

class Test{
    int value;
public:
    void set_value(int n) { value = n; }
    int get_value() { return value; }
};

int main()
{
    Test *t;

    t = new Test[5];

    for(int i = 0; i < 5; i++)
    {
        t[i].set_value(i);
    }

    for(int i = 0; i < 5; i++)
    {
        cout << t->get_value() << endl;
        t++; // t-> 가 가리키고 있는 object 를 어레이 주소 한 칸씩 옮겨주고 있다고 생각하면 쉽다.
    }

    return 0;
}