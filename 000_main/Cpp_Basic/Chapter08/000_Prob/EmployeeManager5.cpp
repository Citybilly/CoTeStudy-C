#include <iostream>
#include <cstring>
using namespace std;

namespace RISK_LEVEL
{
    enum {RISK_C = 1, RISK_B, RISK_A};
}


class Employee
{
private:
    char  name[100];
public:
    Employee(char * name)
    {
        strcpy(this->name, name);
    }
    void ShowYourName() const
    {
        cout << "name: " << name << endl;
    }

    virtual int GetPay() const
    {
        return 0;
    }
    virtual void ShowSalaryInfo() const
    { }
};

class PermanentWorker : public Employee
{
private :
    int salary; // 월급여
public :
    PermanentWorker(char * name, int money)
        : Employee(name), salary(money)
    { }
    int GetPay() const
    {
        return salary;
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl << endl;
    }
};

class TemporaryWorker : public Employee
{
private:
    int workTime;   // 이 달에 일한 시간의 합계
    int payPerHour; // 시간당 급여
public:
    TemporaryWorker(char * name, int pay)
        : Employee(name), workTime(0), payPerHour(pay)
    { }
    void AddWorkTime(int time)  // 일한 시간의 추가
    {
        workTime+=time;
    }
    int GetPay() const  // 이 달의 급여
    {
        return workTime*payPerHour;
    }

    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl << endl;
    }
};

class SalesWorker : public PermanentWorker
{
private:
    int salesResult;    // 월 판매실적
    double bonusRatio;  // 상여금 비율
public:
    SalesWorker(char * name, int money, double ratio)
        : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
    { }
    void AddSalesResult(int value)
    {
        salesResult+=value;
    }

    int GetPay() const
    {
        return PermanentWorker::GetPay()    // PermanentWorker의 GeyPay 함수 호출
                            + (int)(salesResult*bonusRatio);
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl << endl; // SalesWorker의 GetPay 함수가 호출됨
    }
};

class ForeignSaleWorker : public SalesWorker
{
private:
    const int RiskLevel;
    int RiskPay;

public:
    ForeignSaleWorker(char * name, int money, double ratio, int risk)
        : SalesWorker(name,money,ratio), RiskLevel(risk)
    { }

    int GetPay() const
    {
        return SalesWorker::GetPay();
    }

    int GetRiskPay() const
    {
        return SalesWorker::GetPay()*(10*RiskLevel)/100;
    }

    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl; // SalesWorker의 GetPay 함수가 호출됨
        cout << "risk pay: " << GetRiskPay() << endl; //
        cout << "sum: " << GetPay() + GetRiskPay() << endl << endl;     
    }
};

class EmployeeHandler
{
private:
    Employee * empList[50];
    int empNum;

public:
    EmployeeHandler() : empNum(0)
    { }
    void AddEmployee(Employee * emp)
    {
        empList[empNum++]=emp;
    }
    void ShowAllSalaryInfo() const
    {
        for(int i=0; i<empNum; i++)
            empList[i]->ShowSalaryInfo();
    }
    void ShowTotalSalary() const
    {
        int sum = 0;
        for (int i = 0; i<empNum; i++)
            sum+=empList[i]->GetPay();
        cout << "salary sum: " << sum << endl;
    }
    ~EmployeeHandler()
    {
        for(int i=0; i<empNum; i++)
            delete empList[i];
    }
};

int main(void)
{
    // 직원관리를 목적으로 설계된 컨트롤 클래스의 객체생성
    EmployeeHandler handler;

    // 해외 영업직 등록
    ForeignSaleWorker * fseller1 = new ForeignSaleWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
    fseller1 -> AddSalesResult(7000); // 영업실적 7000
    handler.AddEmployee(fseller1);

    ForeignSaleWorker * fseller2 = new ForeignSaleWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
    fseller2 -> AddSalesResult(7000); // 영업실적 7000
    handler.AddEmployee(fseller2);

    ForeignSaleWorker * fseller3 = new ForeignSaleWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
    fseller3 -> AddSalesResult(7000); // 영업실적 7000
    handler.AddEmployee(fseller3);


    // 이번 달에 지불해야 할 급여의 정보
    handler.ShowAllSalaryInfo();
    return 0;
}