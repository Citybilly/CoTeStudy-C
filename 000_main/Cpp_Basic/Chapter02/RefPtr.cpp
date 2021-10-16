#include <iostream>
using namespace std;

int main(void)
{
    int num = 12;
    int *ptr = &num;
    int **dptr = &ptr;

    int &ref=num;   
    int *(&pref)=ptr;   // 포인터 변수의 참조자 선언
    int **(&dpref)=dptr; // 

    cout << ref << endl;
    cout << *pref << endl; 
    cout << **dpref << endl;

    return 0;
}