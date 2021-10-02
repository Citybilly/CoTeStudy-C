#include <iostream>

class Fraction
{
private :
    int m_numerator;    
    int m_denominator;

public:
    Fraction() // default Constroctor, Has same name with class
    {
        m_numerator = 0;
        m_denominator = 1;
    }

int getNumerator() {return m_numerator;}
int getDenominator() {return m_denominator; }
double getValue() { return static_cast<double>(m_numerator)/m_denominator; }
};


int main()
{
    Fraction frac; //
    std::cout << frac.getNumerator() << "/" << frac.getDenominator() << '\n' ;
        // output 0/1
    return 0;
}

