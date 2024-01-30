#include <bits/stdc++.h>

using namespace std;

/**
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
    int getNodePos(Node *head, Node *node)
    {
        int position = 1;
        while (head)
        {
            if (head == node)
            {
                return position;
            }
            else
            {
                head = head->next;
                position++;
            }
        }
        return position;
    }

public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
        {
            return nullptr;
        }
        Node *new_head = new Node(head->val);
        Node *curr_ptr = head->next;
        Node *new_curr_ptr = new_head;

        // Copying values from original linked list to new linked list node by
        // node
        while (curr_ptr)
        {
            new_curr_ptr->next = new Node(curr_ptr->val);
            new_curr_ptr = new_curr_ptr->next;
            curr_ptr = curr_ptr->next;
        }

        // Resetting current pointer for both new and old list to head again to
        // iterate them
        curr_ptr = head;
        new_curr_ptr = new_head;

        while (curr_ptr)
        {
            Node *random = curr_ptr->random;
            Node *random_node = nullptr;
            if (random == nullptr)
            {
                random_node = nullptr; // If random pointer of the current pointer
                                       // from original list points to null, then
                                       // assign null pointer to the random pointer of
                                       // corresponding node in the new list
            }
            else
            {
                int position = getNodePos(head, random);
                random_node = new_head;
                while (--position > 0)
                {
                    random_node =
                        random_node
                            ->next; // If random pointer of the current pointer
                                    // from original list points to null, find
                                    // out the position of the random node and
                                    // assign it to the random pointer of
                                    // corresponding node in the new list
                }
            }
            new_curr_ptr->random = random_node;
            curr_ptr = curr_ptr->next;
            new_curr_ptr = new_curr_ptr->next;
        }
        return new_head;
    }
};