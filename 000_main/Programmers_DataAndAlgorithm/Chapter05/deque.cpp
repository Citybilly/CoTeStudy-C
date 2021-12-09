#include <iostream>
#include <deque>

using namespace std;

// deque [dek] [덱] Double Ended QUEue
// 삽입과 삭제가 양쪽 끝에서 모두 가능한 자료 구조

int main()
{
    deque<int> d {10, 20, 30, 40};
    
    d.push_front(50);
    d.push_back(60);

    for (auto i : d){
        cout << i << ", ";
    }
    cout <<  endl;
    return 0;
}