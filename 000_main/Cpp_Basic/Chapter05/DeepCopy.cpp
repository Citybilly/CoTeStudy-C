#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
    char * name;
    int age;

public:
    Person(char * myname, int myage)
    {
        int len = strlen(myname)+1;
        name = new char[len];
        strcpy(name, myname);
        age = myage;
    }

    void ShowPersonInfo() const
    {
        cout << "이름: " << name << endl;
        cout << "나이: " << age << endl;
    }
    
    ~Person()
    {
        delete []name;
        cout << "Called destructor" << endl;
    }
    // 내가 작성한 코드
    // Person(const Person &copy)
    //     : name(copy.name), age(copy.age)
    // {
    //     int len = strlen(name)+1;
    //     name = new char[len]; // len을 새로 선언할 필요 없었다. 하지만 결과는 정답
    //     strcpy(name, copy.name); 정답
    //     age = copy.age;  // 이미 init 해줬다.
    // }

    // 책에서 제안한 답안
    Person(const Person &copy)
        : age(copy.age)     // age 만을 복사해온다
    {
        name = new char[strlen(copy.name)+1]; // copy.name의 길이를 strlen()+1 로 구하여 char 동적 할당함.
        strcpy(name, copy.name); // 비어있는 char 어레이에 copy.name string 을 복사해준다.
    }
};

int main(void)
{
    Person man1("Lee dong woo", 29);
    Person man2 = man1;

    man1.ShowPersonInfo();
    man2.ShowPersonInfo();
    return 0;
}