/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] <= target && target <= matrix[i][n - 1])
            {
                int l = 0;
                int r = n - 1;
                while (l <= r)
                {
                    int mid = (l + r) / 2;
                    if (matrix[i][mid] == target)
                    {
                        return true;
                    }
                    else if (matrix[i][mid] > target)
                    {
                        r = mid - 1;
                    }
                    else
                    {
                        l = mid + 1;
                    }
                }
            }
        }
        return false;
    }
};
// @lc code=end
