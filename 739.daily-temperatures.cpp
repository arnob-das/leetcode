/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> stack;
        vector<int> res(temperatures.size());

        for (int i = 0; i < temperatures.size(); i++) {
            int currTemp = temperatures[i];
            int currDay = i;

            while (!stack.empty() && stack.top().first < currTemp) {
                int prevDay = stack.top().second;
                res[prevDay] = currDay - prevDay;
                stack.pop();
            }
            stack.push(make_pair(currTemp, currDay));
        }

        return res;
    }
};
// @lc code=end

