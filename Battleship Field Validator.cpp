// Battleship Field Validator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Write a method that takes a field for well-known board game "Battleship" as an argument 
// //and returns true if it has a valid disposition of ships, false otherwise. 
// Argument is guaranteed to be 10*10 two-dimension array. 
// Elements in the array are numbers, 0 if the cell is free and 1 if occupied by ship.
// https://www.codewars.com/kata/52bb6539a4cf1b12d90005b7

#include <iostream>
#include <vector>

using namespace std;

bool validate_battlefield(vector<vector<int>> field)
{
    int battleship = 0;
    int cruiser = 0;
    int destroyer = 0;
    int sub = 0;
    vector<vector<int>> temp = field;
    temp.insert(temp.begin(), { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 });
    temp.push_back({ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 });
    for (int i = 1; i < 11; i++)
    {
        temp[i].insert(temp[i].begin(), 0);
        temp[i].push_back(0);
    }
    for (int i = 1; i < 11; i++)
    {
        for (int j = 1; j < 11; j++)
        {
            if (temp[i][j] == 1)
            {
                if (temp[i + 1][j + 1] == 1 or temp[i - 1][j - 1] == 1 or temp[i + 1][j - 1] == 1 or temp[i - 1][j + 1] == 1)
                {
                    return false;
                }
                if (temp[i + 1][j] == 0 and temp[i - 1][j] == 0 and temp[i][j + 1] == 0 and temp[i][j - 1] == 0)
                {
                    sub += 1;
                    temp[i][j] = 0;
                    continue;
                }
                if (temp[i + 1][j] == 1)
                {
                    if (temp[i + 2][j] == 1)
                    {
                        if (temp[i + 2][j + 1] == 1 or temp[i + 2][j - 1] == 1)
                        {
                            return false;
                        }
                        if (temp[i + 3][j] == 1)
                        {
                            if (temp[i + 3][j + 1] == 1 or temp[i + 3][j - 1] == 1)
                            {
                                return false;
                            }
                            if (temp[i + 4][j] == 1)
                            {
                                return false;
                            }
                            battleship += 1;
                            temp[i + 3][j] = 0;
                            temp[i + 2][j] = 0;
                            temp[i + 1][j] = 0;
                            temp[i][j] = 0;
                            continue;
                        }
                        cruiser += 1;
                        temp[i + 2][j] = 0;
                        temp[i + 1][j] = 0;
                        temp[i][j] = 0;
                        continue;
                    }
                    destroyer += 1;
                    temp[i + 1][j] = 0;
                    temp[i][j] = 0;
                    continue;
                }
                else if (temp[i][j + 1] == 1)
                {
                    if (temp[i][j + 2] == 1)
                    {
                        if (temp[i + 1][j + 2] == 1 or temp[i - 1][j + 2] == 1)
                        {
                            return false;
                        }
                        if (temp[i][j + 3] == 1)
                        {
                            if (temp[i + 1][j + 3] == 1 or temp[i - 1][j + 3] == 1)
                            {
                                return false;
                            }
                            if (temp[i][j + 4] == 1)
                            {
                                return false;
                            }
                            battleship += 1;
                            temp[i][j + 3] = 0;
                            temp[i][j + 2] = 0;
                            temp[i][j + 1] = 0;
                            temp[i][j] = 0;
                            continue;
                        }
                        cruiser += 1;
                        temp[i][j + 2] = 0;
                        temp[i][j + 1] = 0;
                        temp[i][j] = 0;
                        continue;
                    }
                    destroyer += 1;
                    temp[i][j + 1] = 0;
                    temp[i][j] = 0;
                    continue;
                }
            }
        }
    }
    if (battleship == 1 and cruiser == 2 and destroyer == 3 and sub == 4)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    vector<vector<int>> field = {
      {1, 0, 0, 0, 0, 1, 1, 0, 0, 0},
      {1, 0, 1, 0, 0, 0, 0, 0, 1, 0},
      {1, 0, 1, 0, 1, 1, 1, 0, 1, 0},
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
      {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
      {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };
    std::cout << validate_battlefield(field);
}


