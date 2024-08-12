/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int l = 0;
        int r = nums.size() - 1;
        int minimum = nums[0];

        while (l <= r)
        {
            if (nums[l] < nums[r])
            {
                minimum = min(minimum, nums[l]);
                return minimum;
            }
            int mid = (l + r) / 2;
            minimum = min(minimum, nums[mid]);

            if (nums[mid] >= nums[l])
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return minimum;
    }
};
// @lc code=end
