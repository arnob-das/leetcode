/*
 * @lc app=leetcode id=853 lang=cpp
 *
 * [853] Car Fleet
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars;

        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back(make_pair(position[i], time));
        }

        sort(cars.begin(), cars.end());

        double maxTime = 0;
        int res = 0;

        for (int i = n - 1; i >= 0; i--) {
            double curTime = cars[i].second;
            if (curTime > maxTime) {
                maxTime = curTime;
                res++;
            }
        }
        return res;
    }
};
// @lc code=end

