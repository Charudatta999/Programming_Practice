#include <iostream>
#include <vector>
    using namespace std;

    int maxProfit(vector<int> &prices)
    {
        int max_price = 0;
        int index = 0;
        int min_price = 10000;
        for (int i = 0; i < prices.size(); i++)
        {
            if (min_price > prices[i])
            {
                min_price = prices[i];
                index = i;
            }
        }
        if (index == prices.size() - 1)
        {
            for (int i = 0; i < prices.size() - 1; i++)
            {
                if (min_price > prices[i])
                {
                    min_price = prices[i];
                    index = i;
                }
            }
        }
        for (int j = index; j < prices.size(); j++)
        {
            if (max_price < prices[j])
            {
                max_price = prices[j];
            }
        }

        return max_price - min_price;
    }
    //sol2
    int mProfit(vector<int> &prices)
    {
        int maxProfit = 0;
        int minPrice = INT_MAX;
        int tmp;
        for (int &i : prices)
        {
            if (i < minPrice)
            {
                minPrice = i;
            }
            else if ((tmp = (i - minPrice)) > maxProfit)
            {
                maxProfit = tmp;
            }
        }
        return maxProfit;
    }

int main()
{
    int n;
    vector<int> v1 = {2, 4, 1};
    cout<<maxProfit(v1);
}