// Rot13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// ROT13 is a simple letter substitution cipher that replaces a letter with 
// the letter 13 letters after it in the alphabet. ROT13 is an example of the Caesar cipher.
// Create a function that takes a stringand returns the string ciphered with Rot13.
// https://www.codewars.com/kata/530e15517bc88ac656000716

#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

string rot13(string msg)
{
    string newmsg = "";
    string lower[26] = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" };
    string upper[26] = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z" };
    for (int i = 0; i < msg.length(); i++)
    {
        string let(1, msg[i]);
        for (int j = 0; j < 26; j++)
        {
            if (not isalpha(msg[i]))
            {
                newmsg.append(let);
                break;
            }
            else if (let == lower[j])
            {
                int index = j + 13;
                if (index > 25)
                {
                    index -= 26;
                }
                newmsg.append(lower[index]);
            }
            else if (let == upper[j])
            {
                int index = j + 13;
                if (index > 25)
                {
                    index -= 26;
                }
                newmsg.append(upper[index]);
            }
        }
    }
    return newmsg;
}

int main()
{
    std::cout << rot13("^&^*");
}


