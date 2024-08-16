/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int hashArray[256];

        for (int i = 0; i < 256; i++)
        {
            hashArray[i] = -1;
        }

        int l = 0;
        int r = 0;

        int maxLength = 0;

        while (r < s.size())
        {
            if (hashArray[s[r]] != -1)
            {
                if (hashArray[s[r]] >= l)
                {
                    l = hashArray[s[r]] + 1;
                }
            }
            int len = r - l + 1;
            maxLength = max(maxLength, len);
            hashArray[s[r]] = r;
            r++;
        }
        return maxLength;
    }
};
// @lc code=end
