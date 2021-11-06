#include <iostream>
using namespace std;

class SoSimple
{
public:
    static int simObjCnt;

public: // 불필요하지만 변수와 함수의 구분을 목적으로 삽입하기도 함.
    SoSimple()
    {
        simObjCnt++;
    }
};

int SoSimple::simObjCnt=0;

int main(void)
{
    cout << SoSimple::simObjCnt<<"번째 SoSimple 객체" << endl; // 객체를 생성하지도 않았는데 접근가능 = static 변수가 객체 내에 저장되지 않는다.
    SoSimple sim1;
    SoSimple sim2;

    cout << SoSimple::simObjCnt <<"번째 SoSimple 객체" << endl;
    cout << sim1.simObjCnt << "번째 SoSimple 객체" << endl;
    cout << sim2.simObjCnt << "번째 SoSimple 객체" << endl;
    return 0;
}