#pragma once
#include <string>

class Fraction
{   
    //Initialize Fraction function
    public:
    Fraction(int a, int b);

    //Let someone set the numerator and denominator but not actually change variable we are working with
    void setNumerator(int a);

    void setDenominator(int b);

    //Get reciprocal for our current function

    void reciprocal();

    //Convert fraction into double 

    double toDouble();

    //Convert to string 

    std::string toString();

    //Get private variables 
    int getNumerator();
    int getDenominator();

    //multiply fraction by a integer number 
    bool multiply(int c);

    private:
    int numerator;
    int denominator;
};