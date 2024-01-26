#include <bits/stdc++.h>

using namespace std;

/**
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> token_stack;
        unordered_map<string, function<int(int, int)>> operators_map = {
            {"+", [](int a, int b)
             { return a + b; }},
            {"-", [](int a, int b)
             { return a - b; }},
            {"/", [](int a, int b)
             { return a / b; }},
            {"*", [](int a, int b)
             { return a * b; }}};

        for (string &token : tokens)
        {
            if (operators_map[token])
            {
                int second = token_stack.top();
                token_stack.pop();
                int first = token_stack.top();
                token_stack.pop();
                token_stack.push(operators_map[token](first, second));
            }
            else
            {
                token_stack.push(stoi(token));
            }
        }

        return token_stack.top();
    }
};