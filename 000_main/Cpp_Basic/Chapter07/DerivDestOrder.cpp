#include <iostream>
using namespace std;

class SoBase
{
private:
    int baseNum;
public:
    SoBase(int n) : baseNum(n)
    {
        cout << "SoBase(): " << baseNum << endl;
    }
    ~SoBase()
    {
        cout << "~SoBase(): " << baseNum << endl;
    }
};

class SoDerive : public SoBase
{
private:
    int derivNum;
public:
    SoDerive(int n) : SoBase(n), derivNum(n)
    {
        cout << "SoDerived(): " << derivNum << endl;
    }
    ~SoDerive()
    {
        cout << "~SoDerive(): " << derivNum << endl;
    }
};

int main(void)
{
    SoDerive drv1(15);
    SoDerive drv2(27);
    return 0;
}


