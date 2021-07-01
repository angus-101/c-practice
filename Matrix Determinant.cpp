// Matrix Determinant.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Write a function that accepts a square matrix (N x N 2D array) and returns the determinant of the matrix.
// https://www.codewars.com/kata/52a382ee44408cea2500074c

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long determinant(vector<vector<long long>> m)
{
    int n = m[0].size();
    long long det = 0;
    vector<vector<long long>> submatrix((n - 1), vector<long long>((n - 1), 0));
    
    if (n == 1)
    {
        return m[0][0];
    }
    else if (n == 2)
    {
        return ((m[0][0] * m[1][1]) - (m[1][0] * m[0][1]));
    }
    else
    {
        for (int x = 0; x < n; x++)
        {
            int sub_i = 0;
            for (int i = 1; i < n; i++)
            {
                int sub_j = 0;
                for (int j = 0; j < n; j++)
                {
                    if (j == x)
                    {
                        continue;
                    }
                    submatrix[sub_i][sub_j] = m[i][j];
                    sub_j++;
                }
                sub_i++;
            }
            det = det + (pow(-1, x) * m[0][x] * determinant(submatrix));
        }
    }
    return det;
}

int main()
{
    vector<vector<long long>> v = { {3} };
    vector<vector<long long>> vec = { {1, 3},{2, 5} };
    vector<vector<long long>> mat = { {2, 5, 3}, {1, -2, -1}, {1, 3, 4} };
    std::cout << determinant(mat);
}


