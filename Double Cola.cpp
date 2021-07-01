// Double Cola.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Sheldon, Leonard, Penny, Rajesh and Howard are in the queue for a "Double Cola" drink vending machine; 
// there are no other people in the queue. 
// The first one in the queue (Sheldon) buys a can, drinks it and doubles! 
// The resulting two Sheldons go to the end of the queue. 
// Then the next in the queue (Leonard) buys a can, drinks it and gets to the end of the queue 
// as two Leonards, and so on.
// Write a program that will return the name of the person who will drink the n-th cola.
// https://www.codewars.com/kata/551dd1f424b7a4cdae0001f0

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

std::string who_is_next(const std::vector<std::string>& names, long long r)
{
    long long count = 0;
    int end = names.size();
    while (r > end)
    {
        end = (end * 2) + names.size();
        count ++;
    }
    for (int i = (names.size() - 1); i >= 0; i--)
    {
        if ((end - (pow(2, count) - 1)) <= r && r <= end)
        {
            return names[i];
        }
        end -= pow(2, count);
    }
}

int main()
{
    std::vector<std::string> names = { "Sheldon", "Leonard", "Penny", "Rajesh", "Howard" };
    std::cout << who_is_next(names, 1);
}


