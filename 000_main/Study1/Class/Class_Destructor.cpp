#include <iostream>
#include <cstddef>

using namespace std;

class IntArray
{
private:
    int* m_Array;
    int m_Length;

public:
    IntArray(int length)
    {
        m_Array = new int[static_cast<size_t>(length)]{};
        m_Length = length;
    }

    ~IntArray()
    {
        delete[] m_Array;
    }

    void SetValue(int index, int value)
    {
        m_Array[index] = value;
    }

    int GetValue(int index)
    {
        return m_Array[index];
    }

    int GetLength()
    {
        return m_Length;
    }

};

int main()
{
    IntArray ar(10);

    cout << "The value of element 5 before is: " << ar.GetValue(5) <<endl;

    for(int count = 0; count < ar.GetLength();++count)
    {
        ar.SetValue(count,count+1);
    }

    cout << "The value of element 5 after is: " << ar.GetValue(5) << '\n';
    // The value of element 5 is: 6

    return 0;
} // ar 객체는 여기서 삭제되므로 ~IntArray() 소멸자 함수는 여기서 호촐된다.