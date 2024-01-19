#include "vector_functions.h"
#include <algorithm>
#include <iostream>

// write your print vector function here

//Find out how many int within a vector is divisible by 5

int countMultiplesOfFive(std::vector<int> inputVector)
{
    int count = 0; 

    for(auto it = inputVector.begin(); it != inputVector.end(); it++)
    {
        if( *it % 5 == 0 )
        {
            count++;
        }
    }
    

    return count;
}



void addElements(std::vector<int> v, int x, int n)
{
    for(int i = 0; i < n; i++)
    {
        v.push_back(x);
    }
}