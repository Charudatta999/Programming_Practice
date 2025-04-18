/*
Example 1:

Input: intervals = {{1,3},{2,6},{8,10},{15,18}}
Output: {{1,6},{8,10},{15,18}}
Explanation: Since intervals {1,3} and {2,6} overlap, merge them into {1,6}.
Example 2:

Input: intervals = {{1,4},{4,5}}
Output: {{1,5}}
Explanation: Intervals {1,4} and {4,5} are considered overlapping.
*/
// brute force 
#include <vector>
#include <iostream>
#include <algorithm>
std::vector<std::vector<int>> intervals {{1,4},{4,5}}, intervals1  {{1,3},{2,6},{8,10},{15,18}}, intervals2 {{1,4},{0,4}}, intervals3 {{1,4},{2,3}}, intervals4 {{1,4},{1,5}};

bool CheckOverlap(std::vector<int> &arr1, std::vector<int> &arr2)
{
    if(arr1[1] >= arr2[0])
    {
        return true;
    }
    return false;
}
std::vector<int> Merge(std::vector<int> &arr1, std::vector<int> &arr2)
{
    if(arr1[0] >= arr2[0])
        arr1[0] = arr2[0];
    if (arr1[1] < arr2[1])
        arr1[1] = arr2[1];
    
    return arr1;
}
void PrintMatrix(std::vector<std::vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j)
            std::cout << "matrix"<< "[" << i << "]" <<" "<< "["<< j <<"]" << " : "<< matrix[i][j] << " ";
        std::cout << std::endl;
    }
}

void MergeIntervals(std::vector<std::vector<int>> &intervals)
{
    if (intervals.empty()) return;
    std::sort(intervals.begin(),intervals.end());
    std::vector<std::vector<int>> results;
    std::vector<int> current = intervals[0];
    for (size_t i = 1; i < intervals.size(); ++i)
    {
        if (current[0] > intervals[i][0])
        {
            current = Merge(current, intervals[i]); // keep merging
        }
        else
        {
            results.push_back(current); // push merged interval
            current = intervals[i];     // start a new one
        }
    }

    results.push_back(current);
    PrintMatrix(results);
}
int main() 
{
    MergeIntervals(intervals);
    MergeIntervals(intervals1);
    MergeIntervals(intervals2);
    MergeIntervals(intervals4);
    return 0;
}

// ############################################################################################################################
// optimal