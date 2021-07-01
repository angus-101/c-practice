// Adding Big Numbers.cpp : This file contains the 'main' function. Program execution begins and ends there.

// Write a function that returns the sum of two numbers. 
// The input numbers are strings and the function must return a string.
// https://www.codewars.com/kata/525f4206b73515bffb000b21

#include <iostream>

std::string add(std::string a, std::string b)
{
    if (a.length() > b.length())
    {
        swap(a, b);
    }
    std::string str = "";
    int num1 = a.length(), num2 = b.length();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int carry = 0;
    for (int i = 0; i < num1; i++)
    {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        str.push_back((sum % 10) + '0');
        carry = sum / 10;
    }
    for (int i = num1; i < num2; i++)
    {
        int sum = (b[i] - '0') + carry;
        str.push_back((sum % 10) + '0');
        carry = sum / 10;
    }
    if (carry)
    {
        str.push_back(carry + '0');
    }
    reverse(str.begin(), str.end());
    return str;
}

int main()
{
    std::cout << add("12345", "789");
}


