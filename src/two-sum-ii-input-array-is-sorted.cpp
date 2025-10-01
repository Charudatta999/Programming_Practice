#include<iostream>
#include<vector>

std::vector<int> twoSum(std::vector<int> nums, int target)
{
    std::vector<int> result{};
    int start,end;
    start = 0; end = nums.size()-1;

    while (start < end)
    {
        int sum = nums[start] + nums[end];
        if (sum == target) {
            result.push_back(start);
            result.push_back(end);
            break;
        }
        if(sum < target)
        {
            ++start;
            
        }
        else
        {
            --end;
        }
    }
    return result;
}

int main()
{
    int sum = 3;
    std::vector<int> numbers = {1,2,3,4}; 
    
    twoSum(numbers, sum);
}