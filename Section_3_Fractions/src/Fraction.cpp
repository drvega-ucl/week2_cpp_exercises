#include "Fraction.h"
#include <numeric>

Fraction::Fraction(int a, int b)
{
    //Find gcd to simplify fraction
    int gcd = std::gcd(a, b);

    //simplify numerator and denominator
    setNumerator(a/gcd);
    setDenominator(b/gcd);
}

void Fraction::setNumerator(int a)
{
    numerator = a;
}

void Fraction::setDenominator(int b)
{
    denominator = b;
}

void Fraction::reciprocal()
{
    std::swap(numerator,denominator);

}

double Fraction::toDouble()
{
    double result = static_cast<double>(numerator)/denominator;
    return result;
}

std::string Fraction::toString()
{
    if(numerator == 0)
    {
        return "0";
    }
    else
    {
        auto num = std::to_string(numerator);
        auto den = std::to_string(denominator);

        return num + "/" + den;
    }

}

int Fraction::getNumerator()
{
    return numerator;
}

int Fraction::getDenominator()
{
    return denominator;
}

bool Fraction::multiply(int c)
{
    setNumerator(getNumerator() * c);

    return true;
}
