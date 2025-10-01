/*
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
You should aim for a solution with O(n^2) time and O(1) space, where n is the size of the input array.
###########################################################################################################################################
Hint 1
###########################################################################################################################################
A brute force solution would be to check for every triplet in the array. This would be an O(n^3) solution. Can you think of a better way?
###########################################################################################################################################
Hint 2
###########################################################################################################################################
Can you think of an algorithm after sorting the input array? What can we observe by rearranging the given equation in the problem?
We can iterate through nums with index i and get nums[i] = -(nums[j] + nums[k]) after rearranging the equation, making -nums[i] = nums[j] + nums[k]. For each index i, 
we should efficiently calculate the j and k pairs without duplicates. Which algorithm is suitable to find j and k pairs?
###########################################################################################################################################
Hint 3
###########################################################################################################################################
We can iterate through nums with index i and get nums[i] = -(nums[j] + nums[k]) after rearranging the equation, making -nums[i] = nums[j] + nums[k]. 
For each index i, we should efficiently calculate the j and k pairs without duplicates. Which algorithm is suitable to find j and k pairs?
###########################################################################################################################################

Hint 4
###########################################################################################################################################
To efficiently find the j and k pairs, we run the two pointer approach on the elements to the right of index i as the array is sorted. When we run two pointer algorithm, 
consider j and k as pointers (j is at left, k is at right) and target = -nums[i], if the current sum num[j] + nums[k] < target 
then we need to increase the value of current sum by incrementing j pointer. Else if the current sum num[j] + nums[k] > target 
then we should decrease the value of current sum by decrementing k pointer. How do you deal with duplicates?
###########################################################################################################################################
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
std::vector<std::vector<int>> ThreeSum(std::vector<int>& nums)
{
    std::set<std::vector<int>> result;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int start,end;
        start = 1+i;
        end = nums.size() -1;
        while (start < end)
        {
            
            int sum = nums[i] + nums [start] + nums[end];
            if(sum == 0)
            {
                result.insert({nums[i], nums[start], nums[end]});
               
            }
            if (sum < 0)
            {
                ++start;
            }
            else
            {
                --end;
            }
            
        }
        
    }
    return std::vector<std::vector<int>>(result.begin(), result.end());
}

int main()
{
    return 0;
}