#include <iostream>
using namespace std;

class Something
{
private:
    int m_value1;
    double m_value2;
    char m_value3;

public:
    Something(int value1, double value2, char value3 = 'c') 
        : m_value1(1), m_value2(2.2), m_value3('c') // 멤버 초기화 리스트를 통해 멤버 변수를 직접 초기화할 수 있다.
    {
        // 멤버 변수를 여기서 할당할 필요가 없다.
    }

    void print()
    {
    cout << "Something{" << m_value1 << "," << m_value2 << "," << m_value3 << ")\n";
    }
};

int main()
{
    Something something(1,2.2); // value1 = 1, value2=2.2, value3 gets default value 'c'
    something.print();
    return 0;
}
