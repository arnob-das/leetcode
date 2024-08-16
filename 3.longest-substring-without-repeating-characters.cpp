/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int hashArray[256];
        fill(hashArray, hashArray + 256, -1);

        int l = 0;
        int r = 0;
        int maxLength = 0;

        while (r < s.size())
        {
            // if s[r] is within the window length
            if (hashArray[s[r]] != -1 && hashArray[s[r]] >= l)
            {
                l = hashArray[s[r]] + 1;
            }
            maxLength = max(maxLength, r - l + 1);
            hashArray[s[r]] = r;
            r++;
        }
        return maxLength;
    }
};
// @lc code=end
