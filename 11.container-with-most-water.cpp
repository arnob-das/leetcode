/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxAmount = 0;

        int l = 0;
        int r = height.size() - 1;

        while (l < r) {
            int area = (r-l)*min(height[l],height[r]);
            maxAmount = max(area,maxAmount);
            if(height[l]<height[r]){
                l++;
            }else{
                r--;
            }
        }
        return maxAmount;
    }
};
// @lc code=end

