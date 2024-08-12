/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int r = matrix.size();
        int c = matrix[0].size();

        int left = 0;
        int right = r * c - 1;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            int curRow = mid / c;
            int curCol = mid % c;

            int num = matrix[curRow][curCol];

            if (num == target)
            {
                return true;
            }
            else if (num < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return false;
    }
};
// @lc code=end
