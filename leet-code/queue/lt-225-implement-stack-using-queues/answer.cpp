#include <bits/stdc++.h>

using namespace std;

/**
 * - Time complexity:
 * - Push operation: $$O(1)$$
 * - Pop operation: $$O(n)$$, where $$n$$ is the number of elements in the stack (all elements except the last one are moved to the auxiliary queue)
 * - Top operation: $$O(1)$$
 * - Empty check: $$O(1)$$
 *
 * - Space complexity:
 * - Overall space complexity: $$O(n)$$, where $$n$$ is the number of elements in the stack (space required for the main queue and auxiliary queue).
 */

class MyStack
{
public:
    queue<int> *q = nullptr;
    queue<int> *tempQ = nullptr;
    MyStack() : q(new queue<int>), tempQ(new queue<int>) {}

    ~MyStack()
    {
        delete q;
        delete tempQ;
    }

    void push(int x) { q->emplace(x); }

    int pop()
    {
        while (q->size() > 1)
        {
            tempQ->emplace(q->front());
            q->pop();
        }
        int output = q->front();
        q->pop();
        q->swap(*tempQ);
        return output;
    }

    int top() { return q->back(); }

    bool empty() { return q->empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */