#include <iostream>
using namespace std;

string reverse(const string& str)
{
    if  (str.length() == 0)
        return "";
    else
        return reverse(str.substr(1)) + str[0]; // substr(n) 은 string 의 n+1 번째 인자부터 끝 인자 까지를 반환
}

int main()
{
    cout << reverse("Hello") << endl;
    return 0;
}