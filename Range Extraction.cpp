// Range Extraction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Complete the solution so that it takes a list of integers in increasing order and returns a correctly 
// formatted string in the range format.
// https://www.codewars.com/kata/51ba717bb08c1cd60f00002f

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string range_extraction(vector<int> args)
{
    string str = "";
    int count = 0;
    int length = 1;
    while (count + length + 1 <= args.size())
    {
        if (args[count + length] == args[count] + length)
        {
            length++;
            continue;
        }
        else
        {
            if (length > 2)
            {
                str.append(to_string(args[count]) + "-" + to_string(args[count + length - 1]) + ",");
            }
            else if (length == 2)
            {
                str.append(to_string(args[count]) + "," + to_string(args[count + 1]) + ",");
            }
            else
            {
                str.append(to_string(args[count]) + ",");
            }
        }
        count += length;
        length = 1;
    }
    if (count + length + 1 > args.size())
    {
        if (length > 2)
        {
            str.append(to_string(args[count]) + "-" + to_string(args[count + length - 1]) + ",");
        }
        else if (length == 2)
        {
            str.append(to_string(args[count]) + "," + to_string(args[count + 1]) + ",");
        }
        else
        {
            str.append(to_string(args[count]) + ",");
        }
    }
    str = str.substr(0, str.size() - 1);
    return str;
}

int main()
{
    vector<int> args = { -6, -3, -2, -1, 0, 1, 3, 4, 5, 7, 8, 9, 10, 11, 14, 15, 17, 18, 19, 20 };
    std::cout << range_extraction(args);
}


