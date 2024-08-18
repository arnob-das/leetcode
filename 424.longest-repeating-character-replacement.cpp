/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int l = 0;
        int r = 0;
        int maxFreq = 0;

        unordered_map<char, int> map;

        int maxLength = 0;

        while (r < s.size())
        {
            map[s[r]]++;
            maxFreq = max(maxFreq, map[s[r]]);

            if ((r - l + 1) - maxFreq > k)
            {
                map[s[l]]--;
                l++;
            }
            maxLength = max(maxLength, (r - l + 1));
            r++;
        }
        return maxLength;
    }
};
// @lc code=end
