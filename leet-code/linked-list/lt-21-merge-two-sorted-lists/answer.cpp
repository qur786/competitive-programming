#include <bits/stdc++.h>

using namespace std;

/**
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *merged_list = new ListNode();
        ListNode *new_list_head = merged_list;
        while (list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                merged_list->next = list1;
                list1 = list1->next;
            }
            else
            {
                merged_list->next = list2;
                list2 = list2->next;
            }
            merged_list = merged_list->next;
        }

        merged_list->next = list1 ? list1 : list2;
        return new_list_head->next;
    }
};