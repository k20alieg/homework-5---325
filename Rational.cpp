#include "Rational.h"
#include <cstdlib>

// -- private helpers --

// euclidean algorithm, keep it simple to compute the greatest common divisor (GCD)
//the whole point of this is to use fractions to their easiest form - example gcd(10,2) = 2
int Rational::gcd(int a, int b) {
    a = abs(a);   // this here makes sure that both valuses are positive
    b = abs(b);
    // repeat untill the remainder becomes 0
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a; // final valuse of a is the gcd
}

// we have to reduce the fraction, and we need to make sure that the denominator stays positive
// e.g. 10/2 becomes 5/1, and 1/-2 becomes -1/2
void Rational::normalize() {
    // denominator should never be negative
    // if it is, flip both signs
    if (m_denominator < 0) {
        m_numerator = -m_numerator;
        m_denominator = -m_denominator;
    }

    // now divide both by their gcd to reduce fraction to the lowest terms
    int g = gcd(abs(m_numerator), m_denominator);
    m_numerator /= g;
    m_denominator /= g;
}


// -- constructors --
Rational::Rational() : m_numerator(0), m_denominator(1) {
    //  the default constructor: 0/1, already normalized
}
//the parameterized constructoer it creates a rational number from given numberator & denominatorer
// it automatically gets normalizes the fraction
Rational::Rational(int numerator, int denominator)
    : m_numerator(numerator), m_denominator(denominator) {
    normalize();
}


// -- accessors --
// the rational numerator value without modifying objects
int Rational::getNumerator() const {
    return m_numerator;
}

//Returns the denominatoer value without modifying object
int Rational::getDenominator() const {
    return m_denominator;
}


// -- mutators --
// automatically updates the numeratoer & keeps fraction normalized afterward
void Rational::setNumerator(int n) {
    m_numerator = n;
    normalize();
}
//this updates the denominator and it kps the fraction normalized afterward
void Rational::setDenominator(int d) {
    m_denominator = d;
    normalize();        // this maintain simplified form
}


// -- member operators --
// Adds two ratioanal numbers using formula : a/b + c/d = (ad + bc) / bd
Rational Rational::operator+(const Rational& rhs) const {
    int top = m_numerator * rhs.m_denominator + rhs.m_numerator * m_denominator;
    int bot = m_denominator * rhs.m_denominator;
    return Rational(top, bot); // constructor normalizes result automatically
}

//multiplies two rational numbers using this : a/b * c/d = ac / bd
Rational Rational::operator*(const Rational& rhs) const {
    int top = m_numerator * rhs.m_numerator;
    int bot = m_denominator * rhs.m_denominator;
    return Rational(top, bot);
}

// here we will compare 2 ratioanl numbers without converting to deciamls
// a/b < c/d  -->  ad < bc
// cross multiply to avoid any division
bool Rational::operator<(const Rational& rhs) const {
    return m_numerator * rhs.m_denominator < rhs.m_numerator * m_denominator;
}

// mutates LHS and returns a reference to it
Rational& Rational::operator+=(const Rational& rhs) {
    m_numerator = m_numerator * rhs.m_denominator + rhs.m_numerator * m_denominator;
    m_denominator = m_denominator * rhs.m_denominator;
    normalize();
    return *this;
}


// -- non-member (friend) operators --

// handles  5 + r  where LHS is an int
// just wrap the int as a Rational then add normally
Rational operator+(int lhs, const Rational& rhs) {
    return Rational(lhs, 1) + rhs;
}
// overlaods << operator so ratioanl objects can be printed with std::cout
// ex output 3/4 or if dminatoer is 1: 5
// print "n/d" or just "n" if denominator is 1
std::ostream& operator<<(std::ostream& os, const Rational& rhs) {
    if (rhs.m_denominator == 1)
        os << rhs.m_numerator;
    else
        os << rhs.m_numerator << "/" << rhs.m_denominator;
    return os;
}
