/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void generate(int n, int openN, int closeN, string str,
                  vector<string> &res)
    {
        if (openN == n && closeN == n)
        {
            res.push_back(str);
            return;
        }
        cout << str << endl;
        if (openN < n)
        {
            generate(n, openN + 1, closeN, str + '(', res);
        }
        if (closeN < openN)
        {
            generate(n, openN, closeN + 1, str + ')', res);
        }
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        generate(n, 0, 0, "", res);
        return res;
    }
};
// @lc code=end
