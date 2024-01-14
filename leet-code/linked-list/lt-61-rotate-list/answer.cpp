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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next || k == 0)
            return head;

        ListNode *new_head = head;
        ListNode *curr = head;
        ListNode *last_node = head;
        int length = 1;
        while (curr->next)
        {
            curr = curr->next;
            length += 1;
        }

        last_node = curr;

        k = k % length;

        if (k == 0)
        {
            return new_head;
        }
        int nth_node = length - k;

        curr = head;

        while (--nth_node > 0)
        {
            curr = curr->next;
        }

        ListNode *remaining_nodes = curr->next;
        curr->next = nullptr;
        last_node->next = new_head;
        new_head = remaining_nodes;

        return new_head;
    }
};