/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */
// @lc code=start

// leetcode 76 Minimum Window Substring
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (t.size() == 0)
        {
            return "";
        }

        int l = 0;
        int r = 0;
        int startIndex = 0;
        int minLength = INT_MAX;
        int have = 0;

        unordered_map<char, int> charFreqOfT;
        unordered_map<char, int> windowCharFreq;

        for (int i = 0; i < t.size(); i++)
        {
            charFreqOfT[t[i]]++;
        }

        // number of unique characters of t
        int need = charFreqOfT.size();

        while (r < s.size())
        {
            char letter = s[r];
            if (charFreqOfT[letter] > 0)
            {
                windowCharFreq[letter]++;

                if (windowCharFreq[letter] == charFreqOfT[letter])
                {
                    have++;
                }
            }
            while (have == need)
            {
                int length = r - l + 1;
                if (length < minLength)
                {
                    minLength = length;
                    startIndex = l;
                    ;
                }

                if (charFreqOfT[s[l]])
                {
                    windowCharFreq[s[l]]--;
                    if (windowCharFreq[s[l]] < charFreqOfT[s[l]])
                    {
                        have--;
                    }
                }
                l++;
            }
            r++;
        }

        if (minLength == INT_MAX)
        {
            return "";
        }

        return s.substr(startIndex, minLength);
    }
};
// @lc code=end
