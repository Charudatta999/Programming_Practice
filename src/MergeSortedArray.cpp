#include <vector>
#include <iostream>

std::vector<int>  nums1 = {1,2,3,0,0,0},  nums2 = {2,5,6};
int m = 3, n = 3;

void Merge( std::vector<int> &arr1, std::vector<int> &arr2 )
{
    size_t i,j = 0;

    while (i < arr1.size())
    {
        if(arr1[i]<arr2[j])
        {
            if (i < arr1.size())
            {
                if(arr1[i+1] > arr2[j])
                {
                    for (size_t k = i; k < arr2.size(); k++)
                    {
                        arr1[i]
                    }
                    
                }
            }
            
        }
    }
    
    
}

int main() {
    Merge(nums1 , nums2);    
    return 0;
}