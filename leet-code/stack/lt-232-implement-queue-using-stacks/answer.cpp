#include <bits/stdc++.h>

using namespace std;

/**
 * - Time complexity:
 *  - Push: $$O(1)$$
 *  - Pop/Peek: Amortized $$O(1)$$ (although in the worst case it can be $$O(n)$$ due to the need for transferring elements)
 * - Space complexity:
 *  - Additional space used by the temporary stack: $$O(n)$$
 */

class MyQueue
{
private:
    stack<int> s;
    stack<int> tempS;

public:
    MyQueue() {}

    void push(int x) { s.emplace(x); }

    int pop()
    {
        while (s.size() > 0)
        {
            tempS.emplace(s.top());
            s.pop();
        }
        int output = tempS.top();
        tempS.pop();
        while (tempS.size() > 0)
        {
            s.emplace(tempS.top());
            tempS.pop();
        }
        return output;
    }

    int peek()
    {
        while (s.size() > 0)
        {
            tempS.emplace(s.top());
            s.pop();
        }
        int output = tempS.top();
        while (tempS.size() > 0)
        {
            s.emplace(tempS.top());
            tempS.pop();
        }
        return output;
    }

    bool empty() { return s.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */