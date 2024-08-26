/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// leetcode 21 Merge Two Sorted Lists

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *newNode = new ListNode();
        ListNode *temp = newNode;

        while (list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                newNode->next = list1;
                list1 = list1->next;
            }
            else
            {
                newNode->next = list2;
                list2 = list2->next;
            }
            newNode = newNode->next;
        }
        if (!list1)
        {
            while (list2)
            {
                newNode->next = list2;
                newNode = newNode->next;
                list2 = list2->next;
            }
        }
        if (!list2)
        {
            while (list1)
            {
                newNode->next = list1;
                newNode = newNode->next;
                list1 = list1->next;
            }
        }
        return temp->next;
    }
};
// @lc code=end
