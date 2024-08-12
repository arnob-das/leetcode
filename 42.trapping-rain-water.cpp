/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // using two array maxLeft and ,maxRight
    /*
    int trap(vector<int>& height) {
        int res = 0;
        int n = height.size();
        vector<int> maxLeft(n);
        vector<int> maxRight(n);

        for (int i = 1; i < n; i++) {
            maxLeft[i] = max(maxLeft[i - 1], height[i - 1]);
        }

        for (int i = n - 2; i >= 0; i--) {
            maxRight[i] = max(maxRight[i + 1], height[i + 1]);
        }

        for (int i = 0; i < n; i++) {
            int waterUnit = min(maxLeft[i], maxRight[i]) - height[i];
            if (waterUnit > 0) {
                res += waterUnit;
            }
        }
        return res;
    }
    */

    // using only one array "maxRight"

    /*
    int trap(vector<int>& height) {
        int res = 0;
        int maxLeft = 0;
        int n = height.size();
        vector<int> maxRight(n);

        for (int i = n - 2; i >= 0; i--) {
            maxRight[i] = max(maxRight[i + 1], height[i + 1]);
        }

        for (int i = 0; i < n; i++) {
            if (i > 0) {
                maxLeft = max(maxLeft, height[i - 1]);
            }
            int waterUnit = min(maxLeft, maxRight[i]) - height[i];
            if (waterUnit > 0) {
                res += waterUnit;
            }
        }
        return res;
    }
    */

    // optimal solution with space complexity O(1)

    int trap(vector<int>& height) {
        int res = 0;
        int n = height.size();
        int leftMax = 0;
        int rightMax = 0;
        int left = 0;
        int right = n - 1;

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                } else {
                    res += leftMax - height[left];
                }
                left++;
            } else {
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                } else {
                    res += rightMax - height[right];
                }
                right--;
            }
        }

        return res;
    }
};
// @lc code=end

