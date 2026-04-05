#include <iostream>    //this library allows us to print output using the std::cout
#include "Rational.h"   //we hre have to include the rational class - so we create rational objetcs

int main() {
    // build the three starting rationals
    Rational r1(2, 3);      // here it r1 represents 1 fraction 2/3
    Rational r2(5, 4);      // same thing here yet it fraction 5/4
    Rational r3(10, 1);     // this one represnts the whole number, denominator = 1

    // print the using the overloaded << operator while doing this it will allow rational onjects to be printed like normal #'s
    std::cout << r1 << std::endl;   // they will print   2/3
    std::cout << r2 << std::endl;   //                   5/4
    std::cout << r3 << std::endl;   //                   10

    // r1 + r2 and r1 * r2
    // what we did here is used the overloaded arithmetic operators defined in the rational class
    std::cout << r1 + r2 << std::endl;   // 2/3 + 5/4 = 23/12
    std::cout << r1 * r2 << std::endl;   // 2/3 * 5/4 = 5/6

    // int + Rational using the friend operator - so int 5 is right away converted in rational(5,1) before addi
    std::cout << 5 + r3 << std::endl;   // 5 + 10 = 15 then the result is 15

    // increment r1 by 1/3
    // the operator+= right up modifies r1 directly instead of creating a new object
    r1 += Rational(1, 3);
    std::cout << r1 << std::endl;   // after adding r will become 2/3 + 1/3 = 1

    // compare r1 and r2
    // r1 is now 1, r2 is 5/4 = 1.25 so this means that the condition will turn out to become true
    if (r1 < r2)
        std::cout << "yes" << std::endl;
    else
        std::cout << "no" << std::endl;
    return 0;
}
