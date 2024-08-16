/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// [121] Best Time to Buy and Sell Stock
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxProfit = 0;
        int minPrice = INT_MAX;

        for (int i = 0; i < prices.size(); i++)
        {
            if (minPrice > prices[i])
            {
                minPrice = prices[i];
            }
            else
            {
                maxProfit = max(maxProfit, prices[i] - minPrice);
            }
        }
        return maxProfit;
    }
};
// @lc code=end
