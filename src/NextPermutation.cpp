#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void nextPermutation(std::vector<int>& arr)
{
    int breakIndex=-1;
    for (int i = arr.size()-2; i >=0; i--)
    {
        if(arr[i]  < arr[i+1])
        {
            breakIndex=i;
            break;
        }
    }
    if(breakIndex == -1)
    {
        std::reverse(arr.begin(), arr.end());
        return;
    }
    for (int i = arr.size()-1; i >= breakIndex; i--)
    {
        if(arr[i] > arr[breakIndex])
        {
            std::swap(arr[i],arr[breakIndex]);
            break;
        }
    }

    std::reverse(arr.begin() + (breakIndex+1),arr.end());
    
}

int main() {
    std::vector<int> arr = {3,2,1};
    nextPermutation(arr);
    for (auto it = arr.begin(); it != arr.end(); ++it)
    {
       std::cout << *it << " ";
    }
    std::cout << std::endl;
    return 0;
}