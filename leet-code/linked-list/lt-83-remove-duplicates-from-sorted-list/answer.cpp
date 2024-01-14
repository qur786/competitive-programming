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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *curr_ptr = head;
        ListNode *new_head = new ListNode();
        ListNode *new_ptr = new_head;
        while (curr_ptr)
        {
            if (curr_ptr->next == nullptr ||
                curr_ptr->val != curr_ptr->next->val)
            {
                new_ptr->next = curr_ptr;
                new_ptr = new_ptr->next;
            }
            curr_ptr = curr_ptr->next;
        }
        new_ptr->next = nullptr;

        return new_head->next;
    }
};