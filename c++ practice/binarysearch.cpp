#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

int searcher(std::vector<int> values, int low, int high, int mid, int target)
{

    if (high == low)
    {
        std::cout << "not found" << std::endl;
        return -1;
    }
    if (target == values[low]){
        std::cout << "At Position " << low << std::endl;
        std::cout << "found" << std::endl;
        return low;
    }
    if (target == values[mid]) {
        std::cout << "At Position " << mid << std::endl;
        std::cout << "found" << std::endl;
        return mid;
    }
    if (target == values[high]){
        std::cout << "At Position " << high << std::endl;

        std::cout << "found" << std::endl;
        return high;
    }
     if (target < values[mid] && target > values[low]){
        
        low = low++;
        high = mid;
        mid = (low + high) / 2;
        searcher(values, low, high, mid, target);
    }
     if (target > values[mid] && target < values[high]){
        low = mid + 1;
        mid = (low + high) / 2;
        searcher(values, low, high, mid, target);
    }
    return -1;
}

int binary_search(std::vector<int> values, int target)
{
    int mid {0};
    int low {0};
    int high = (values.size())-1;
    mid = (low + high) / 2;
    return searcher(values, low, high, mid, target);
}

int main()
{
    std::cout << "Enter List Of Numbers In sorted Manner";
    std::stringstream ss;
    std::string str;
    getline(std::cin, str);
    replace( str.begin(), str.end(), ',', ' ');
    ss << str;
    
    int v;
    std::vector<int> a  {};
    while (ss >> v)
    {
        std::cout << v << std::endl;
        a.push_back(v);
    }
    if(a.size() <1){
        std::cout << "No inputs given" << std::endl;
    exit(0);
    }
    std::cout << "Enter An element To Search fro the list" << std::endl;

    int target {};

    std::cout << target << std::endl;

    std::cin >> target;
    
    std::cout<<binary_search(a, target) << std::endl;
    return 0;
}