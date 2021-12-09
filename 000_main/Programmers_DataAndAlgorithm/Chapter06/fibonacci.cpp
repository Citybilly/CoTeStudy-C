#include <iostream>

using namespace std;


long long fibo(int n)
{
    if(n <= 1)
        return n;
    else
        return fibo(n-1) + fibo(n - 2);
}



int main()
{
    for (int i = 1; i <= 10; i++)
        cout << fibo(i) << ", ";
    cout << endl;

    cout << fibo(40) << endl;
    cout << fibo(50) << endl;   // 엄청 오래걸림! 이유 : 종복되는 부분 문제로 인해 계산 효율이 떨어짐 (Overlapping Subproblem)
                                // 캐시(cache) 를 사용하여 문제를 해결할 수 있음.

    return 0;
}