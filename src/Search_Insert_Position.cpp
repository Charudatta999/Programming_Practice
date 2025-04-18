/*
Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4
*/
#include<iostream>
#include<string>
#include<vector>
// soln 1 : ✅
/*
int searchInsert(std::vector<int>& nums, int target) 
{
    for(size_t i = 0; i < nums.size(); i++)
    {
        int num = nums[i];
        if( num == target)
        {
            return i;
        }
        else if (num >= target)
        {
            return i;
        }
    }
    return nums.size();
}
*/
/*
    soln2 binary Search:
*/
int searchInsert(std::vector<int>& nums, int target) 
{
    size_t high{nums.size()};
    size_t low{0};
    
    while(low < high)
    {
        size_t mid{low + (high - low) /2};
        if(nums[mid] == target)
        {
            return mid; 
        }
        if(nums[mid] > target)
        {
            return --mid;
        }
        if(nums[mid] < target)
        {
            low=mid+1;
        }
        else
        {
            high = mid -1;
        }
    }
    return nums.size();

}

int main()
{
    std::vector<int>nums{1,3,5,6};
    int target = 5;
    int target1 = 2;
    int target2 = 7;

    // if(searchInsert(nums,target) == 2)
    // {
    //     std::cout << "passed" << std::endl;
    // }
    // else
    // {
    //     std::cout << "failed " << searchInsert(nums,target) << " Expected Value is : 2" << std::endl;
    // }

    // if(searchInsert(nums,target1) == 1)
    // {
    //     std::cout << "passed" << std::endl;
    // }
    // else
    // {
    //     std::cout << "failed " << searchInsert(nums,target1) << " Expected Value is :  1" << std::endl;
    // }

    // if(searchInsert(nums,target2) == 4)
    // {
    //     std::cout << "passed" << std::endl;
    // }
    // else
    // {
    //     std::cout << "failed " << searchInsert(nums,target) << " Expected Value is : 4" << std::endl;
    // }

    if(searchInsert(nums,0) == 0)
    {
        std::cout << "passed" << std::endl;
    }
    else
    {
        std::cout << "failed " << searchInsert(nums,target) << " Expected Value is : 0" << std::endl;
    }
    return 0;
}