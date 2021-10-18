#include <iostream>
using namespace std;

class SiniveCap // 콧물 처치용 캡슐
{
public:
    void Take() const {cout << "콧물이 싹~ 납니다." << endl;}
};

class SneezeCap // 재채기 처치용 캡슐
{
public:
    void Take() const {cout << "재채기가 멋습니다." << endl;}
};

class SnuffleCap // 재채기 처치용 캡슐
{
public:
    void Take() const {cout << "코가 뻥 뚫립니다." << endl;}
};

class CONTAC600
{
private:
    SiniveCap sin;
    SneezeCap sne;
    SnuffleCap snu;

public:
    void Take() const
    {
        sin.Take();
        sne.Take();
        snu.Take();
    }
};

class ColdPatient
{
public:
    void TakeCONTA600(const CONTAC600 &cap) const {cap.Take();}
};

int main(void)
{
    CONTAC600 cap;
    ColdPatient sufferer;
    sufferer.TakeCONTA600(cap);
    return 0;
}