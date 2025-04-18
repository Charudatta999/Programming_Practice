#include <iostream>
#include <vector>

std::vector<int> pop_element_at_index(std::vector<int>& nums, int elemnt_to_find) {

    size_t end = nums.size();
    if (end >= 0) {
        for(size_t i = 0 ; i < end; i++ )
        {
            if(nums[i] == elemnt_to_find)
            {
                nums.erase(nums.begin()+i);
                nums.push_back(elemnt_to_find); 
            }
        } 
    } else {
        std::cerr << "Index out of bounds" << std::endl;
    }
    return nums;
}



int main() {
    std::vector<int> vec = {0,0,1};

    int elemnt_to_find = 0;
    std::vector<int> updated_vec = pop_element_at_index(vec,elemnt_to_find);

    std::cout << "Updated vector: ";
    for (int i : updated_vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}