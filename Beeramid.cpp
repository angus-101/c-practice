// Beeramid.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Complete the beeramid function to return the number of complete levels of a 
// beer can pyramid you can make, given the parameters of:
// 1. your referral bonus, and
// 2. the price of a beer can
// https://www.codewars.com/kata/51e04f6b544cf3f6550000c1

#include <iostream>
#include <cmath>

int beeramid(int bonus, double price)
{
    if (bonus <= 0)
    {
        return 0;
    }
    int cans = floor(bonus / price);
    int count = 1;
    while (cans >= 0)
    {
        cans -= pow(count, 2);
        count++;
    }
    return (count - 2);
}

int main()
{
    std::cout << beeramid(10, 2);
}


