#include "Fraction.h"
#include <iostream>

bool approx(double a, double b, double epsilon)
{
    return std::abs(a - b) <= epsilon;
}

bool checkDoubleConversion()
{
    // We use the approx feature here because floating point arithmetic is not exact
    // epsilon is the amount of error that we allow 
    bool okay = approx(Fraction(1, 2).toDouble(), 0.5, 1e-10);

    okay &= approx(Fraction(2, 3).toDouble(), 2.0/3.0, 1e-10);

    okay &= approx(Fraction(0, 15).toDouble(), 0, 1e-10);

    okay &= approx(Fraction(2, 4).toDouble(), 0.5, 1e-10);

    return okay;
}

bool checkStringConversion()
{
    bool okay = Fraction(1, 2).toString() == "1/2";

    okay &= Fraction(2,4).toString() == "1/2";

    okay &= Fraction(3,9).toString() == "1/3";

    okay &= Fraction (8,12).toString() == "2/3";

    okay &= Fraction(2, 3).toString() == "2/3";

    okay &= Fraction(7, 9).toString() == "7/9";

    okay &= Fraction(0, 5).toString() == "0";

    okay &= Fraction(0, 12).toString() == "0";

    return okay;
}

bool checkMultiplyConversion()
{
    Fraction test1 = Fraction(1,2);
    test1.multiply(2);

    bool okay = approx(test1.toDouble(), 1.0 , 1e-10);

    Fraction test2 = Fraction(3,9);
    test2.multiply(0);

    okay &= approx(test2.toDouble(), 0.0, 1e-10);

    Fraction test3 = Fraction(6,10);
    test3.multiply(5);

    okay &= approx(test3.toDouble(), 3.0, 1e-10);


    return okay;
}

int main()
{
    std::cout << "Check double conversion." << std::endl;
    std::cout << (checkDoubleConversion() ? "Double conversion okay." : "Double conversion incorrect.") << std::endl;

    std::cout << "Check string conversion." << std::endl;
    std::cout << (checkStringConversion() ? "String conversion okay." : "String conversion incorrect.") << std::endl;

    std::cout << "Check multiplication conversion." << std::endl;
    std::cout << (checkMultiplyConversion() ? "Multiplication conversion okay." : "Multiplication conversion incorrect.") << std::endl;

    
    
    return 0;
}