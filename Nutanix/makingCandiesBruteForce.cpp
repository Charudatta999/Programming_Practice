#include <iostream>

using namespace std;

long minimumPasses(long m, long w, long p, long n)
{
    int candies = 0;
    int count = 0;
    while (candies < n)
    {
        if (w * m >= n / 2 || candies >= n / 2)
        {
            count++;
            return count;
        }
        else if (candies < n)
        {
            if (m < w)
            {
                int m_to_buy = candies / p;
                m += m_to_buy;
                candies -= m_to_buy * p;
                count++;
            }
            else
            {
                int w_to_buy = candies / p;
                candies -= w_to_buy * p;
                w += w_to_buy;
                count++;
            }
        }

        candies += w * m;
    }
    return count;
}

int main()
{
    cout << minimumPasses(1, 1, 6, 45);

    return 0;
}