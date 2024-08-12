/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        int len = s.length();

        for (int i = 0; i < len; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if (st.empty()) {
                    return false;
                }

                char c = st.top();

                if ((s[i] == ')' && c == '(') || (s[i] == '}' && c == '{') ||
                    (s[i] == ']' && c == '[')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }

        if (st.empty()) {
            return true;
        } else {
            return false;
        }
    }
};
// @lc code=end

