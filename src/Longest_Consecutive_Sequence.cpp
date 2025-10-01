#include <iostream>
#include <vector>
#include <unordered_set>

int longestConsecutive(std::vector<int>& nums) 
{
    int len{0};
    std::unordered_set<int> numsSet;
    for (size_t i = 0; i < nums.size(); i++)
    {
        numsSet.insert(nums[i]);
    }

    for (auto num : nums)
    {
        
            if (!numsSet.count(num-1))
            {
                int currLen = 0;
                int number = num;
                while (0 < numsSet.count(number))
                {
                    currLen += 1;
                    number += 1;
                }
                len = std::max(currLen,len);
            }
    }
    
    return len;   
}

int main()
{
    std::vector<int> nums = {2,20,4,10,3,4,5};
    int result = longestConsecutive(nums);
    std::cout << "Longest consecutive sequence length: " << result << std::endl;
    return 0;
}