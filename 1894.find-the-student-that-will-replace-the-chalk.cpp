/*
 * @lc app=leetcode id=1894 lang=cpp
 *
 * [1894] Find the Student that Will Replace the Chalk
 */

// @lc code=start

// leetcocde 1894. Find the Student that Will Replace the Chalk
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long neededChalk = 0;

        for (int c : chalk) {
            neededChalk += c;
        }

        k = k % neededChalk;

        for (int i = 0; i < chalk.size(); i++) {
            if (k < chalk[i]) {
                return i;
            }
            k -= chalk[i];
        }
        return 0;
    }
};
// @lc code=end

