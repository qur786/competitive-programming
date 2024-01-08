#include <bits/stdc++.h>

using namespace std;

/**
 * Time complexity: O(n)
 * Space complexity: O(n)
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int remainder = 0;
        ListNode *header, *result;
        header = result = new ListNode();
        while (l1 != nullptr && l2 != nullptr)
        {
            int sum = l1->val + l2->val + remainder;
            remainder = sum / 10;
            result->val = sum % 10;
            l1 = l1->next;
            l2 = l2->next;
            if (l1 != nullptr && l2 != nullptr)
            {
                result->next = new ListNode();
                result = result->next;
            }
        }

        while (l1 != nullptr)
        {
            int sum = l1->val + remainder;
            remainder = sum / 10;
            int newDigit = sum % 10;
            result->next = new ListNode(newDigit);
            result = result->next;
            l1 = l1->next;
        }

        while (l2 != nullptr)
        {
            int sum = l2->val + remainder;
            remainder = sum / 10;
            int newDigit = sum % 10;
            result->next = new ListNode(newDigit);
            result = result->next;
            l2 = l2->next;
        }

        if (remainder > 0)
        {
            result->next = new ListNode(remainder);
        }

        return header;
    }
};