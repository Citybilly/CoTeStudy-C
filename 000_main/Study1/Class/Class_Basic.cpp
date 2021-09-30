#include  <iostream>
using namespace std;
/* getSum() is written in class*/
class Transcation {
    public :
        void init(int amount) { sum = amount; }
        void send(int amount) { sum -= amount; }
        void receive(int amount) { sum += amount; }
        void getSum() { cout << sum << endl; }

    private :
        int sum;

};
/* getSum() is written outside of class */
class Transcation2 {
    public :
        void init(int amount) { sum = amount; }
        void send(int amount) { sum -= amount; }
        void receive(int amount) { sum += amount; }
        void getSum();

    private :
        int sum;
};
void Transcation2::getSum() {cout << sum << endl; }  // sometimes this method is much readable if fucntion has big size

int main()
{
    Transcation A, B;

    A.init(1000);
    B.init(2000);

    int amount = 500;
    A.send(amount);
    B.receive(amount);

    A.getSum();
    B.getSum();

    return 0;
}