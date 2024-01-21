#include "vector_functions.h"
#include <algorithm>
#include <iostream>

// write your print vector function here

//Find out how many int within a vector is divisible by 5

int countMultiplesOfFive(std::vector<int> inputVector)
{
    //Defining my lambda function

    // the [] initializes my lambda function, in this instance it does not take any variables from around it's scope
    // () in here I define what sort of parameters my lambda function is taking in. For my case I am taking an interger
    // -> points to the type the return should be, in this case it should return true if my number is divisble by 5
    auto isDivBy5 = [](int number) -> bool {
        return number % 5 == 0;
    };

    //Use std::count_if function, this function takes a start, end, and lambda function
    //This function creates a integer variable called in whose value is the number of integers within a vector is divisble by 5
    int count = std::count_if(inputVector.begin(), inputVector.end(), isDivBy5);

    return count;
}



void addElements(std::vector<int> v, int x, int n)
{
    for(int i = 0; i < n; i++)
    {
        v.push_back(x);
    }
}