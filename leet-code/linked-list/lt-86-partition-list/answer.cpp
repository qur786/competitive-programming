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
    ListNode *partition(ListNode *head, int x)
    {
        if (!head || !head->next)
            return head;

        ListNode *greater_than_x_node = nullptr, *greater_than_x_prev_node = nullptr,
                 *greater_than_later_list = nullptr, *curr_ptr = head;

        while (curr_ptr->next)
        {
            if (curr_ptr->val >= x)
            {
                greater_than_x_node = curr_ptr;
                greater_than_later_list = curr_ptr->next;
                greater_than_x_node->next = nullptr;
                break;
            }
            greater_than_x_prev_node = curr_ptr;
            curr_ptr = curr_ptr->next;
        }

        if (!greater_than_x_node || !greater_than_later_list)
        {
            return head;
        }

        ListNode *greater_than_first_list_last_node = greater_than_x_node;

        while (greater_than_later_list)
        {
            if (greater_than_later_list->val < x)
            {
                ListNode *temp = greater_than_later_list->next;
                if (!greater_than_x_prev_node)
                {
                    greater_than_later_list->next = greater_than_x_node;
                    head = greater_than_later_list;
                    greater_than_x_prev_node = head;
                    greater_than_later_list = temp;
                }
                else
                {
                    greater_than_x_prev_node->next = greater_than_later_list;
                    greater_than_x_prev_node->next->next = greater_than_x_node;
                    greater_than_later_list = temp;
                    greater_than_x_prev_node = greater_than_x_prev_node->next;
                }
            }
            else
            {
                greater_than_first_list_last_node->next = greater_than_later_list;
                greater_than_later_list = greater_than_later_list->next;
                greater_than_first_list_last_node = greater_than_first_list_last_node->next;
                greater_than_first_list_last_node->next = nullptr;
            }
        }

        return head;
    }
};