/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
#include<bits/stdc++.h>;
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freqMap;
        vector<vector<int>> bucket(n + 1);
        vector<int> res;

        for (int i = 0; i < n; i++) {
            freqMap[nums[i]]++;
        }

        for (auto& pair : freqMap) {
            bucket[pair.second].push_back(pair.first);
        }

        for (int i = bucket.size() - 1; i >= 0 && res.size() < k; i--) {
            for (int num : bucket[i]) {
                res.push_back(num);
                if (res.size() == k) {
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end

