/*
 * @lc app=leetcode id=1945 lang=cpp
 *
 * [1945] Sum of Digits of String After Convert
 */

// @lc code=start

// leetcode 1945. Sum of Digits of String After Convert
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getLucky(string s, int k) {
        string number = "";

        for (char c : s) {
            number += to_string(c - 'a' + 1);
        }

        while (k > 0) {
            int sum = 0;

            for (char c : number) {
                sum += c - '0';
            }
            number = to_string(sum);
            k--;
        }
        return stoi(number);
    }
};
// @lc code=end

