#include <bits/stdc++.h>

using namespace std;

/**
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

class Solution
{
public:
    unordered_map<char, function<int(int, int)>> operator_map = {
        {'+', [](int a, int b)
         { return a + b; }},
        {'-', [](int a, int b)
         { return a - b; }},
        {'/', [](int a, int b)
         { return a / b; }},
        {'*', [](int a, int b)
         { return a * b; }}};

    unordered_map<char, int> ass_map = {
        {'+', 1},
        {'-', 1},
        {'*', 2},
        {'/', 2},
    };

    int calculate(string s)
    {
        stack<int> operands;
        stack<char> operators;

        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (ass_map[c])
            {
                if (operators.size() > 0 &&
                    ass_map[c] <= ass_map[operators.top()])
                {
                    while (operators.size() > 0 &&
                           ass_map[c] <= ass_map[operators.top()])
                    {
                        int second = operands.top();
                        operands.pop();
                        int first = operands.top();
                        operands.pop();
                        operands.push(
                            operator_map[operators.top()](first, second));
                        operators.pop();
                    }
                    operators.push(c);
                }
                else
                {
                    operators.push(c);
                }
            }
            else if (c >= '0' && c <= '9')
            {
                int operand = c - '0';
                if (i > 0 && s[i - 1] >= '0' && s[i - 1] <= '9')
                {
                    operands.top() = operands.top() * 10 + operand;
                }
                else
                {
                    operands.push(operand);
                }
            }
        }

        while (operators.size() > 0)
        {
            int second = operands.top();
            operands.pop();
            int first = operands.top();
            operands.pop();
            operands.push(operator_map[operators.top()](first, second));
            operators.pop();
        }

        return operands.top();
    }
};