
#include <iostream>
#include<vector>



using namespace std;

int removeDuplicates(vector<int> &nums)
{
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
    return nums.size();
}

int main()
{
    vector<char> nums;
    vector<int> vi{0,0,1,1,1,2,2,3,3,4};
    
    removeDuplicates(vi)
   

    return 0;
}
