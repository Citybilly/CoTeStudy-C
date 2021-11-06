#include <iostream>
using namespace std;

class Car
{
private:
    int gasolineGauge;
public:

    Car (int n)
        : gasolineGauge(n)
    { }

    int GetGasGauge()
    {
        return gasolineGauge;
    }
};

class HybridCar : public Car
{
    private:
        int electricGauge;
    public:

        HybridCar (int i, int j)
            : Car(i), electricGauge(j)
        { }

        int GetElcGauge()
        {
            return electricGauge;
        }
};

class HybridWaterCar : public HybridCar     // 하이브리드 워터카
{
private:
    int waterGauge;
public:

    HybridWaterCar(int i, int j, int k)
        : HybridCar(i,j), waterGauge(k)
    { }

    void ShowCurrentGauge()
    {
        cout << "잔여 가솔린: " << GetGasGauge() << endl;
        cout << "잔여 전기량: " << GetElcGauge() << endl;
        cout << "잔여 워터량: " << waterGauge << endl;
    }
};


int main(void)
{
    HybridWaterCar HWC(1,2,3);
    HWC.ShowCurrentGauge();

    return 0;
}