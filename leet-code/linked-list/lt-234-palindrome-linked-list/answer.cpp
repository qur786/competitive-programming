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
    bool isPalindrome(ListNode *head)
    {
        if (!head && !head->next)
        {
            return true;
        }

        ListNode *fast = head, *slow = head;

        while (fast && fast->next)
        {
            slow = slow->next; // Middle pointer
            fast = fast->next->next;
        }

        ListNode *prev = nullptr, *curr = slow, *next = nullptr;

        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        while (prev)
        {
            if (prev->val != head->val)
            {
                return false;
            }

            prev = prev->next;
            head = head->next;
        }

        return true;
    }
};