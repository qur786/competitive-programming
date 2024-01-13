#include <bits/stdc++.h>

using namespace std;

/**
 * Time complexity: O(nlogk)
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
    ListNode *merge(ListNode *new_list, ListNode *input_list)
    {
        ListNode *sorted_list = new ListNode();
        ListNode *head = sorted_list;
        while (new_list && input_list)
        {
            if (new_list->val <= input_list->val)
            {
                sorted_list->next = new_list;
                new_list = new_list->next;
            }
            else
            {
                sorted_list->next = input_list;
                input_list = input_list->next;
            }
            sorted_list = sorted_list->next;
        }

        sorted_list->next = new_list ? new_list : input_list;

        return head->next;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
        {
            return nullptr;
        }
        /*
        Use a divide-and-conquer approach to iteratively merge pairs of
        lists.
        */
        int interval = 1;
        while (interval < lists.size())
        {
            for (int i = 0; i + interval < lists.size(); i += 2 * interval)
            {
                /*
                Merge lists at indices i and i+interval and update the
                original list at index i.
                */
                lists[i] = merge(lists[i], lists[i + interval]);
            }
            // Double the interval for the next iteration.
            interval *= 2;
        }

        // Return the final merged sorted list.
        return lists[0];
    }
};