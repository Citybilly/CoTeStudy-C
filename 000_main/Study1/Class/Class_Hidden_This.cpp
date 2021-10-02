#include <iostream>
using namespace std;

class  Simple
{
private:
    /* data */
    int m_ID;

public:
    Simple(int id)
    {
         SetID(id);
    }

    void SetID(int id)
    {
         m_ID = id;
    }
    
    int GetID()
    {
        return m_ID;
    }
};

int main()
{
    Simple simple(1);
    simple.SetID(2);
    cout << simple.GetID() << endl; // 2

    return 0;
}