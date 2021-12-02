#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
    forward_list<int> l1 {10, 20, 30, 40};
    l1.push_front(40);  // 40, 10, 20, 30, 40
    l1.push_front(30);  // 30, 40, 10, 20, 30, 40

    for (auto a : l1)
        cout << a << ", ";
    cout << endl;

    int cnt = distance(l1.begin(), l1.end());
    cout << cnt << endl;

    l1.remove(40); // 30, 10, 20, 30, // 특정 값 삭제
    l1.remove_if([](int n) { return n > 20; }); // 20보다 큰 경우 삭제 // 람다함수 이용 람다함수에 대해 알아봐야 할 것 같다

    for (auto a : l1)
        cout << a << ", ";
    cout << endl;

    return 0;

}