#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Stack
{
public:
    Stack() {}

    void push(const T& e) { v.push_back(e); } // 백터 맨 마지막에 윈소 추가
    void pop() { v.pop_back(); } // 백터 맨 마지막 원소 삭제
    const T& top() const { return v.back(); }  // 앞의 const 참조형은 다른 함수에서 스택에 들어있는 값을 변경하지 못하게 하기 위함
                                                // 뒤의 const 는 이 함수에서 맴버변수 v를 변경하지 않는다는 선언

    bool empty() const { return v.empty(); }
    int size() const { return v.size(); }

private:
    std::vector<T> v;
};

int main()
{
    Stack<int> stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.pop();
    
    cout << stk.top() << endl;
    stk.push(40);

    while (!stk.empty()){
        auto& e = stk.top();
        cout << e << ", ";
        stk.pop();
    }
    cout << endl;

    return 0;
}