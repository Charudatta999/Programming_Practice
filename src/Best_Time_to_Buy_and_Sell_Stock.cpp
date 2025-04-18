#include <iostream>
#include <string>
#include <vector>
#include <climits>
int getProfit(std::vector<int>& prices)
{
    int max {0};
    int i{0};
    int j{1};
    while(j < prices.size())
    {
        int curMax{0};
       
        if(prices[i] > prices[j])
        {
           i = j;
        }
        else
        {
             curMax = prices[j] - prices[i];
        }
        if(curMax > max)2
        {
            max = curMax;
        }
        j++;
    }

    return max;
}
int main()
{
    std::vector<int> prices={7,1,5,3,6,4};
    if(getProfit(prices) == 5)
    {
        std::cout << "first case passed" << std::endl;
    }
    else
    {
        std::cout << "first case failed" << std::endl;
    }
    prices={7,6,4,3,1};
    if(getProfit(prices) == 0)
    {
        std::cout << "Second Case Passed" << std::endl;
    }
    else
    {
        std::cout << "Second case Failed" << std::endl;
    }
    prices = {2,4,1};
    if(getProfit(prices) == 2)
    {
        std::cout << "Thrid Case Passed" << std::endl;
    }
    else
    {
        std::cout << "Third case Failed" << std::endl;
    }
    return 0;
}