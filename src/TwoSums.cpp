#include<iostream>
#include<vector>
#include <unordered_map>
std::vector<int> twoSum(std::vector<int>& nums, int target) 
{
    std::unordered_map<int, int> numsIndexMap;
    int firstIndex,secondElement;
    
    for (int i =0; i < nums.size(); i++)
    {
      
      int subTarget = target - nums[i];
      auto it = numsIndexMap.find(subTarget);
      if(it != numsIndexMap.end())
      {
        secondElement = it->second;
        firstIndex = i;
      }
      numsIndexMap[nums[i]]=i;
    }
    return {firstIndex,secondElement};
}

int main()
{
	int target{6};
	std::vector<int> nums ={3,3};
  auto resultVector = twoSum(nums, target);
  std::cout << resultVector[0] << " " << resultVector[1] << std::endl;
	return 0;
}
