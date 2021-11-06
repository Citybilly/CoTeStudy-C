#include <iostream>
#include <cstring>
using namespace std;

class MyfriendInfo
{
private:
    char * name;
    int age;

public:

    MyfriendInfo(char * Name, int Age)
        : age(Age)
    {
        name = new char[strlen(Name)+1];
        strcpy(name, Name);
    }

    ~MyfriendInfo()
    {
        delete []name;
    }

    void ShowMyFriendInfo()
    {
        cout << "이름: " << name << endl;
        cout << "나이: " << age << endl;
    }
};

class MyFriendDetailInfo : public MyfriendInfo
{
private:
    char * addr;
    char * phone;
public:

    MyFriendDetailInfo(char * Name, int Age, char * Addr, char * Phone)
        : MyfriendInfo(Name, Age)
    {
        addr = new char[strlen(Addr)+1];
        strcpy(addr, Addr);
        phone = new char[strlen(Phone)+1];
        strcpy(phone, Phone);
    }

    ~MyFriendDetailInfo()
    {
        delete []addr;
        delete []phone;
    }

    void ShowMyFriendDetailInfo()
    {
        ShowMyFriendInfo();
        cout << "주소: " << addr << endl;
        cout << "전화: " << phone << endl << endl;
    }
};

int main()
{
    MyFriendDetailInfo Dog("강아지", 1, "개집", "000");
    Dog.ShowMyFriendDetailInfo();
    return 0;
}