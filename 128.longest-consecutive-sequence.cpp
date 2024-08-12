/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if (nums.empty()) {
            return 0;
        }

        unordered_set<int> set(nums.begin(), nums.end());

        int maxCount = 0;

        for (int num : nums) {
            if (!set.count(num - 1)) {
                int currentNum = num;
                int count = 1;

                while (set.count(currentNum + 1)) {
                    currentNum++;
                    count++;
                }
                maxCount = max(maxCount, count);
            }
        }
        return maxCount;
    }
};
// @lc code=end

