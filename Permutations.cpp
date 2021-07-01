// Permutations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// In this kata you have to create all permutations of an input string and remove duplicates, if present. 
// This means, you have to shuffle all letters from the input in all possible orders.
// https://www.codewars.com/kata/5254ca2719453dcc0b00027d

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> permutations(string s)
{
    vector<string> perm;
    std::sort(s.begin(), s.end());
    do
    {
        perm.push_back(s);
    } while (std::next_permutation(s.begin(), s.end()));
    return perm;
}

int main()
{
    string s = "abcde";
    vector<string> perm = permutations(s);
    for (int i = 0; i < perm.size(); i++)
    {
        std::cout << perm[i] << "\n";
    }
}


