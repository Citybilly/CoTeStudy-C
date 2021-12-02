#include <iostream>
#include <stack>
#include <vector>
//문자열 뒤집기
//문자열의 각 문자를 스택에 push한 후, 다시 스택에서 문자를 하나씩 pop하여 출력 문자열을 생성

using namespace std;

string reverse(const string& str)
{
    stack<char> stk;

    for(char c : str)
        stk.push(c);

    string res;
    
    while (!stk.empty()) { 
        res += stk.top();
        stk.pop();
    }
    return res;
}

template <typename T>
void reverse(vector<T>& vec)
{
    stack<T> stk;

    for(const auto& e : vec)
        stk.push(e);

    for (int i = 0; i < vec.size(); i++){
        vec[i] = stk.top();
        stk.pop();
    }
}




int main()
{
    string str1 = "HELLO";
    string str2 = "ALGORITHM";

    cout << str1 << " -> " << reverse(str1) << endl;
    cout << str2 << " -> " << reverse(str2) << endl;

//    vector<int> vec {10, 20, 30, 40, 50};
    vector<string> vec {"John", "loves", "Jane"};

    reverse(vec);

    for (auto e : vec)
        cout << e << ", ";
    cout << endl;

    return 0;
}