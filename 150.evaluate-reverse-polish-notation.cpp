/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(const string&token:tokens){
            if(token!="+" && token!="-" && token!="*" && token!="/"){
                st.push(stoi(token));
            }
            else{
                int val2 = st.top();
                st.pop();
                int val1 = st.top();
                st.pop();
                if(token=="+"){
                    st.push(val1+val2);
                }
                else if(token=="-"){
                    st.push(val1-val2);
                }
                else if(token=="*"){
                    st.push(val1*val2);
                }
                else if(token=="/"){
                    st.push(val1/val2);
                }
            }
        }
        return st.top();
    }
};
// @lc code=end

