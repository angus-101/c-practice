// Sum of Intervals.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Write a function called sum_intervals() that accepts an array of intervals, 
// and returns the sum of all the interval lengths. Overlapping intervals should only be counted once.
// https://www.codewars.com/kata/52b7ed099cdc285c300001cd

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int sum_intervals(vector<pair<int, int>> intervals) {
    int count = 0;
    for (int i = 0; i < intervals.size(); i++)
    {
        for (int j = 0; j < intervals.size(); j++)
        {
            if ((intervals[j].first < intervals[i].first and intervals[j].second >= intervals[i].first and intervals[j].second <= intervals[i].second) or (intervals[j].second > intervals[i].second and intervals[j].first >= intervals[i].first and intervals[j].first <= intervals[i].second) or (intervals[j].first <= intervals[i].first and intervals[j].second >= intervals[i].second) and intervals[j].first != -1 and intervals[i].first != -1  and i != j)
            {
                if (intervals[j].first < intervals[i].first and intervals[j].second >= intervals[i].first and intervals[j].second <= intervals[i].second)
                {
                    intervals[i].first = intervals[j].first;
                }
                if (intervals[j].second > intervals[i].second and intervals[j].first >= intervals[i].first and intervals[j].first <= intervals[i].second)
                {
                    intervals[i].second = intervals[j].second;
                }
                if (intervals[j].first <= intervals[i].first and intervals[j].second >= intervals[i].second)
                {
                    intervals[i].first = intervals[j].first;
                    intervals[i].second = intervals[j].second;
                }
                intervals[j].first = -1;
                intervals[j].second = -1;
            }
        }
    }
    for (int i = 0; i < intervals.size(); i++)
    {
        if (intervals[i].first != -1)
        {
            count += (intervals[i].second - intervals[i].first);
        }
    }
    return count;
}


int main()
{
    vector<pair<int, int>> intervals = {
                                       {10, 20},
                                       {5, 25},
                                       {30, 31}
                                       };
    cout << sum_intervals(intervals);
}


