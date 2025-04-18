#include <iostream>
#include <string>
#include <vector>

int maximumSubarray(std::vector<int> arr)
{
    int maxSub=arr[0];
    int curSum{0};
    for (size_t i = 0; i < arr.size(); i++)
    {
        if(curSum < 0)
        {
            curSum = 0;
        }
        curSum+=arr[i];
        if(maxSub < curSum)
            maxSub = curSum; 
    }
    return maxSub;
}
int main() {
    std::vector<int> arr{-2,1,-3,4,-1,2,1,-5,4};
    std::cout << maximumSubarray(arr) << std::endl;
    return 0;
}