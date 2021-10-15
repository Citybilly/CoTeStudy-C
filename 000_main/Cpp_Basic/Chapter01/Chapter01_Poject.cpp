#include <iostream>

using namespace std;
const int NAME_LEN = 20;

int Menu(void);
void MakeAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowAllAccInfo(void);
int findAddr(int ID);

typedef struct
{
    /* data */
    int accID;
    int balance;
    char name[NAME_LEN];
}Account;

Account accARR[100];
int accNum = 0;

int main()
{
    int Selected(0);

    while(1)
    {
        Selected = Menu();
        switch(Selected)
        {
            case 1 : 
                MakeAccount();
            break;
            
            case 2 :
                DepositMoney();
            break;

            case 3 :
            
            break;

            case 4 :
                ShowAllAccInfo();
            break;
            
            case 5 :

            break;
        }
    }
    return 0;
}


int Menu(void)
{
    int Select;

    cout << "-----Menu-----" << endl;
    cout << "1. 계좌개설" << endl;
    cout << "2. 입 금" << endl;
    cout << "3. 출 금" << endl;
    cout << "4. 계좌정보 전체 출력" << endl;
    cout << "5. 프로그램 종료" << endl;
    cout << "선택: ";
    cin >> Select;
    // cout << Select << endl;
    return Select;
}

void MakeAccount(void)
{
    cout << "[계좌계설]" << endl;
    cout << "계좌ID: ";
    cin >> accARR[accNum].accID;
 //   cout << endl;
    cout << "이 름: ";
    cin >> accARR[accNum].name;
 //   cout << endl;
    cout << "입금액: ";
    cin >> accARR[accNum].balance;
 //   cout << endl;
    accNum++;
}

void DepositMoney(void)
{
    int Addr;
    int ID;
    int inputMoney;

    cout << "[입 금]" << endl;
    cout << "계좌ID: ";
    cin >> ID;
    cout << endl;
//    cout << ID << endl;
    cout << "입금액: ";
    cin >> inputMoney;

    Addr = findAddr(ID);
    accARR[Addr].balance = accARR[Addr].balance + inputMoney;
    cout << endl;
    cout << "입금완료" << endl;
}
void WithdrawMoney(void)
{

}
void ShowAllAccInfo(void)
{
    for (int i = 0; i < accNum; i++)
    {
        cout << "계좌ID: " << accARR[i].accID << endl;
        cout << "이 름: " << accARR[i].name << endl;
        cout << "잔 액: " << accARR[i].balance << endl;
    }
}

int findAddr(int ID)
{
    int retVal(NULL);

    for(int i=0; i < accNum; i++)
    {
        if(accARR[i].accID == ID)
        {
            retVal = i; 
            return retVal;
        }
    }
    return retVal;
}