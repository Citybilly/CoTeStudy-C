#include <cassert>
#include <iostream>

using namespace std;

class Fraction
{
private:
    int m_numerator;
    int m_denominator;

public:
    Fraction() // Default Constroctor
    {
        m_numerator = 0;
        m_numerator = 1;
    }

    // Constructor with Parameters, on parameter having a default value
    Fraction(int numerator, int denominator = 1)
    {
        assert(denominator != 0);
        m_numerator = numerator;
        m_denominator = denominator;
    }
    
    int getNumerator() { return m_numerator; }
    int getDenominator() {return m_denominator; }
    double getValue() { return static_cast<double>(m_numerator)/m_denominator; }
    


};

#define ON              (1)
#define OFF             (0)
#define MODE_DIRECT     ON
#define MODE_UNIFORM    OFF
#define MODE_COPY       OFF 



int main()
{
#if MODE_DIRECT
    int x(5);                // Direct initialize an integer
    Fraction fiveThird(5,3); // Direct initialization of a Fraction, calls Fraction(int, int) constructor

    cout << x << endl;
    cout << fiveThird.getDenominator() << endl;
    cout << fiveThird.getNumerator() << endl;
    cout << fiveThird.getValue() <<  endl;
#endif

#if MODE_UNIFORM
    int x{5};                   // Uniform initialization of an integer
    Fraction fiveThird{5,3};    // Uniform initialization of a Fraction, calls Fraction(int, int) constructor    
    Fraction six(6);            // Calls Fraction(int,int) constructor, second parameter uses a default value

    cout << x << endl;
    cout << fiveThird.getDenominator() << endl;
    cout << fiveThird.getNumerator() << endl;
    cout << fiveThird.getValue() <<  endl;

    cout << six.getDenominator() << endl;
    cout << six.getNumerator() << endl;
    cout << six.getValue() <<  endl;
#endif

#if MODE_COPY
    int x = 6;                  // Copy initialize an integer
    Fraction six = Fraction(6); // Copy initialize a Fraction, will call Fraction(6,1)
    Fraction seven = 7;         // Copy initialize a Fraction, The compiler will try to find a way to convert 7 to a Fraction, which will invoke the Fraction(7, 1) constructor.
    
    cout << x << endl;
    cout << six.getDenominator() << endl;
    cout << six.getNumerator() << endl;
    cout << six.getValue() <<  endl;

    cout << seven.getDenominator() << endl;
    cout << seven.getNumerator() << endl;
    cout << seven.getValue() <<  endl;    
#endif
    return 0;
}