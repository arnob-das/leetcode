/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int rest = target - nums[i];

            if (numMap.count(rest)) {
                return {i, numMap[rest]};
            }

            numMap[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end

