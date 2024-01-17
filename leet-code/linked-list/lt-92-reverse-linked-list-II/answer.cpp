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
private:
    ListNode *reverse(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode *rev_list = nullptr, *curr = head;
        while (curr)
        {
            ListNode *temp_head = curr->next;
            curr->next = rev_list;
            rev_list = curr;
            curr = temp_head;
        }
        return rev_list;
    }

public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (!head || !head->next)
        {
            return head;
        }

        ListNode *left_end = nullptr, *right_start = nullptr, *curr = nullptr;

        for (int i = 1; i <= right; i++)
        {
            if (i == left && i > 1)
            {
                left_end = curr;
            }
            if (curr != nullptr)
            {
                curr = curr->next;
            }
            else
            {
                curr = head;
            }
        }

        if (curr)
        {
            right_start = curr->next;
            curr->next = nullptr;
        }

        ListNode *list_segment = nullptr;

        if (left_end)
        {
            list_segment = left_end->next;
            left_end->next = nullptr;
        }
        else
        {
            list_segment = head;
        }

        ListNode *rev_list = reverse(list_segment);

        if (left_end)
        {
            left_end->next = rev_list;
        }
        else
        {
            head = rev_list;
        }

        ListNode *rev_list_end = rev_list;

        if (right_start)
        {
            while (rev_list_end->next)
            {
                rev_list_end = rev_list_end->next;
            }
            rev_list_end->next = right_start;
        }

        return head;
    }
};