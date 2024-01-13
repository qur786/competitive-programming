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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (n <= 0)
        {
            return head;
        }
        ListNode *prev = nullptr, *slow = head, *fast = head;
        while (--n >= 0 && fast)
        {
            fast = fast->next;
        }

        if (!fast && n == -1)
        {
            ListNode *delete_node = head;
            head = head->next;
            delete delete_node;
        }

        if (fast)
        {
            while (fast)
            {
                prev = slow;
                slow = slow->next;
                fast = fast->next;
            }

            prev->next = slow->next;
            delete slow;
        }

        return head;
    }
};