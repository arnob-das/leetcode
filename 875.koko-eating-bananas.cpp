/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int k = right;

        while (left <= right)
        {
            int mid = (left + right) / 2;

            long long hour = 0;

            for (int i = 0; i < piles.size(); i++)
            {
                hour += (piles[i] + mid - 1) / mid;
            }

            if (hour <= h)
            {
                right = mid - 1;
                k = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return k;
    }
};
// @lc code=end
