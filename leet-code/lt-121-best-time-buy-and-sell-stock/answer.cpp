#include <bits/stdc++.h>

using namespace std;

/**
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int start = 0, max_profit = 0, i = 1;
        while (i < prices.size())
        {
            int profit = prices[i] - prices[start];
            if (profit > max_profit)
            {
                max_profit = profit;
            }
            else if (prices[i] < prices[start])
            {
                start = i;
            }
            i++;
        }

        return max_profit;
    }
};