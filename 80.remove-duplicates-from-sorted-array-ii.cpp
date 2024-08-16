/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();
        int index = 2;
        
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] != nums[index - 2]) {
                nums[index++] = nums[i];
            }
        }
        
        return index;
    }
};
// @lc code=end

