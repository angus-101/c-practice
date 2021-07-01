// Sudoku Solution Validator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Write a function validSolution that accepts a 2D array representing a Sudoku board, 
// and returns true if it is a valid solution, or false otherwise. 
// The cells of the sudoku board may also contain 0's, which will represent empty cells. 
// Boards containing one or more zeroes are considered to be invalid solutions.
// https://www.codewars.com/kata/529bf0e9bdf7657179000008

#include <iostream>
#include <algorithm>
#include <vector>

bool validSolution(unsigned int board[9][9])
{
    unsigned int temp[9][9], transpose[9][9];
    std::vector<int> one, two, three, four, five, six, seven, eight, nine;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == 0)
            {
                return false;
            }
            temp[i][j] = board[i][j];
            transpose[j][i] = board[i][j];
            if (0 <= i and i < 3 and 0 <= j and j < 3)
            {
                one.push_back(board[i][j]);
            }
            else if (0 <= i and i < 3 and 3 <= j and j < 6)
            {
                two.push_back(board[i][j]);
            }
            else if (0 <= i and i < 3 and 6 <= j and j < 9)
            {
                three.push_back(board[i][j]);
            }
            else if (3 <= i and i < 6 and 0 <= j and j < 3)
            {
                four.push_back(board[i][j]);
            }
            else if (3 <= i and i < 6 and 3 <= j and j < 6)
            {
                five.push_back(board[i][j]);
            }
            else if (3 <= i and i < 6 and 6 <= j and j < 9)
            {
                six.push_back(board[i][j]);
            }
            else if (6 <= i and i < 9 and 0 <= j and j < 3)
            {
                seven.push_back(board[i][j]);
            }
            else if (6 <= i and i < 9 and 3 <= j and j < 6)
            {
                eight.push_back(board[i][j]);
            }
            else if (6 <= i and i < 9 and 6 <= j and j < 9)
            {
                nine.push_back(board[i][j]);
            }
        }
    }
    for (int i = 0; i < 9; i++)
    {
        std::sort(temp[i], temp[i] + 9);
        std::sort(transpose[i], transpose[i] + 9);
        std::sort(one.begin(), one.end());
        std::sort(two.begin(), two.end());
        std::sort(three.begin(), three.end());
        std::sort(four.begin(), four.end());
        std::sort(five.begin(), five.end());
        std::sort(six.begin(), six.end());
        std::sort(seven.begin(), seven.end());
        std::sort(eight.begin(), eight.end());
        std::sort(nine.begin(), nine.end());
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (temp[i][j] != (j + 1))
            {
                return false;
            }
            if (transpose[i][j] != (j + 1))
            {
                return false;
            }
        }   
    }
    for (int i = 0; i < 9; i++)
    {
        if (one[i] != (i + 1))
        {
            return false;
        }
        else if (two[i] != (i + 1))
        {
            return false;
        }
        else if (three[i] != (i + 1))
        {
            return false;
        }
        else if (four[i] != (i + 1))
        {
            return false;
        }
        else if (five[i] != (i + 1))
        {
            return false;
        }
        else if (six[i] != (i + 1))
        {
            return false;
        }
        else if (seven[i] != (i + 1))
        {
            return false;
        }
        else if (eight[i] != (i + 1))
        {
            return false;
        }
        else if (nine[i] != (i + 1))
        {
            return false;
        }
        
    }
    return true;
}

int main()
{
    unsigned int board[9][9] = { {5, 3, 4, 6, 7, 8, 9, 1, 2},
                             {6, 7, 2, 1, 9, 5, 3, 4, 8},
                             {1, 9, 8, 3, 4, 2, 5, 6, 7},
                             {8, 5, 9, 7, 6, 1, 4, 2, 3},
                             {4, 2, 6, 8, 5, 3, 7, 9, 1},
                             {7, 1, 3, 9, 2, 4, 8, 5, 6},
                             {9, 6, 1, 5, 3, 7, 2, 8, 4},
                             {2, 8, 7, 4, 1, 9, 6, 3, 5},
                             {3, 4, 5, 2, 8, 6, 1, 7, 9} };
    std::cout << validSolution(board);
}


