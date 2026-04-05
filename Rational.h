#pragma once        //header file must be included one
#include <iostream> //this here is needed for std::ostream
//this class represent rational number - mostibly fractions. ex: 3/4, 5/2, -7/8 etc.
class Rational {
private:
    int m_numerator;    // this here stores the numerator
    int m_denominator;  // this here stores the denominator

    static int gcd(int a, int b);   // made to compute gcd & used to simplify fractions like 10/2 to 5/1
    void normalize();               //helper function to reuce fraction and fix signs & to endure denomiatoer stays postive

public:
    // constructors
    Rational();
    Rational(int numerator, int denominator);   // consturctors with numneratoer & denominatoer ratioanl (3,4) creates 3/4

    // accessors functions to return to the numberatoer & does not play with the object for both
    int getNumerator() const;
    int getDenominator() const;

    // mutators
    void setNumerator(int n); // the mutator function to change the numerator value
    void setDenominator(int d); // the muator funtion to denominatoer value

    // member operators (LHS is a Rational)
    Rational operator+(const Rational& rhs) const; //the operator+ overload for adding 2 rational objects ex r1 + r2
    Rational operator*(const Rational& rhs) const; //operator* overaload for multiplying two ratioanl objects ex r1 * r2
    bool operator<(const Rational& rhs) const;  // here the opreator < overlaod for comparing two rational objects r1 < r2
    Rational& operator+=(const Rational& rhs);  // friend operatior+ overload when LEFT side is an integer r1 +=r2

    // non-member operators declared as friends (LHS is NOT a Rational)
    // example : cout << r1;
    friend Rational operator+(int lhs, const Rational& rhs);
    friend std::ostream& operator<<(std::ostream& os, const Rational& rhs);
};
