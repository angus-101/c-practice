// First Variation on Caesar Cipher.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// This program performs a variation of the Caesar shift. 
// The shift increases by 1 for each character (on each iteration).
// https://www.codewars.com/kata/5508249a98b3234f420000fb

#include <iostream>
#include <string>
#include <vector>

class CaesarCipher
{
public:
    static std::vector<std::string> movingShift(const std::string& s, int shift);
    static std::string demovingShift(std::vector<std::string>& s, int shift);
};

std::vector<std::string> CaesarCipher::movingShift(const std::string& s, int shift)
{
    std::string str;
    std::vector<char> lower = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
    std::vector<char> upper = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
    for (int i = 0; i < s.length(); i++)
    {
        bool found = false;
        for (int j = 0; j < 26; j++)
        {
            if (s[i] == lower[j])
            {
                found = true;
                str.push_back(lower[(j + shift) % 26]);
                break;
            }
            else if (s[i] == upper[j])
            {
                found = true;               
                str.push_back(upper[(j + shift) % 26]);
                break;
            }
        }
        if (found == false)
        {
            str.push_back(s[i]);
        }
        shift++;
    }
    std::vector<int> lengths;
    std::vector<std::string> vec = { "", "", "", "", "" };
    int count = 0;
    double n = s.length();
    int first = ceil(n / 5);
    int num = floor(n / first);
    int second = n - (first * num);
    for (int i = 0; i < num; i++)
    {
        lengths.push_back(first);
    }
    if (lengths.size() < 5)
    {
        lengths.push_back(second);
    }
    for (int i = lengths.size(); i < 5; i++)
    {
        lengths.push_back(0);
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < lengths[i]; j++)
        {
            vec[i].push_back(str[count + j]);
        }
        count += lengths[i];
    }
    return vec;
}

std::string CaesarCipher::demovingShift(std::vector<std::string>& s, int shift)
{
    std::string str;
    std::string str1;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < s[i].length(); j++)
        {
            str.push_back(s[i][j]);
        }
    }
    std::vector<char> lower = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
    std::vector<char> upper = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
    for (int i = 0; i < str.length(); i++)
    {
        bool found = false;
        for (int j = 0; j < 26; j++)
        {
            if (str[i] == lower[j])
            {
                found = true;
                str1.push_back(lower[((((j - shift) % 26) + 26) % 26)]);
                break;
            }
            else if (str[i] == upper[j])
            {
                found = true;
                str1.push_back(upper[((((j - shift) % 26) + 26) % 26)]);
                break;
            }
        }
        if (found == false)
        {
            str1.push_back(str[i]);
        }
        shift++;
    }
    return str1;
}

int main()
{
    std::string s = "The code word is: gamer";
    std::vector<std::string> vec = CaesarCipher::movingShift(s, 1);
    std::string str = CaesarCipher::demovingShift(vec, 1);
    for (int i = 0; i < 5; i++)
    {
        std::cout << vec[i] << "\n";
    }
    std::cout << str;
    
}


