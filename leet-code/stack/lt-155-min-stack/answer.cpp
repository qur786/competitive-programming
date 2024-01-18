#include <bits/stdc++.h>

using namespace std;

/**
 * Time complexity: O(1)
 * Space complexity: O(n)
 */

class MinStack
{
public:
    vector<int> stack;
    vector<int> minStack;
    MinStack() {}

    void push(int val)
    {
        stack.push_back(val);
        int m = min(minStack.empty() ? INT_MAX : minStack.back(), val);
        minStack.push_back(m);
    }

    void pop()
    {
        stack.pop_back();
        minStack.pop_back();
    }

    int top() { return stack.back(); }

    int getMin() { return minStack.back(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */