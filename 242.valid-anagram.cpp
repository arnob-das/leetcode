/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start

#include<bits/stdc++.h>;
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        unordered_map<char, int> hashMap;

        int len = s.length();

        for (int i = 0; i < len; i++) {
            hashMap[s[i]]++;
        }

        for (int i = 0; i < t.length(); i++) {
            hashMap[t[i]]--;
        }

        for (int i = 0; i < t.length(); i++) {
            if (hashMap[t[i]] != 0) {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end

