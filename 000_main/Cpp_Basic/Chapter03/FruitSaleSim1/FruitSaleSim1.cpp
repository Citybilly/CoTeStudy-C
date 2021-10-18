#include <iostream>
using namespace std;

class FruitSeller
{
private:
    int APPLE_PRICE;
    int numOfApples;
    int myMoney;

public:
    void InitMembers(int price, int num, int money)
    {
        APPLE_PRICE = price;
        numOfApples=num;
        myMoney=money;
    }
    int SaleApples(int money)
    {
        int num=money/APPLE_PRICE;
        numOfApples-=num;
        myMoney+=money;
        return num;
    }
    void ShowSalesResult()
    {
        cout << "남은 사과: " << numOfApples << endl;
        cout << "판매 수익: " << myMoney << endl << endl;
    }
};

class FruitBuyer
{
    int myMoney;        // private
    int numOfApples;    // private

public:
    void InitMebmers(int money)
    {
        myMoney=money;
        numOfApples=0;
    }
    void BuyApples(FruitSeller &seller, int money)
    {
        numOfApples+=seller.SaleApples(money);
        myMoney -= money;
    }
    void ShowBuyResults()
    {
        cout << "현재 잔액: " << myMoney << endl;
        cout << "" << numOfApples << endl << endl;
    }
};

int main(void)
{
    FruitSeller seller;
    seller.InitMembers(1000, 20, 0);
    FruitBuyer buyer;
    buyer.InitMebmers(5000);
    buyer.BuyApples(seller,2000);   // 과일의 구매

    cout << "과일 판매자의 현황" << endl;
    seller.ShowSalesResult();
    cout << "과일 구매자의 현황" << endl;
    buyer.ShowBuyResults();
    return 0;
}