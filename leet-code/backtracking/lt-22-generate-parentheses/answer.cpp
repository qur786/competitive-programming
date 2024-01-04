#include <bits/stdc++.h>

using namespace std;

/**
 * Time complexity: O(4^n / sqrt{n})
 * Space complexity:O(4^n / sqrt{n})
 */

class Solution
{
public:
    vector<string> all_parenthesis;

    void generate(string &curr, int leftPar, int rightPar)
    {
        if (leftPar == 0 && rightPar == 0)
        {
            all_parenthesis.push_back(curr);
            return;
        }

        if (leftPar > 0)
        {
            curr.push_back('(');
            generate(curr, leftPar - 1, rightPar);
            curr.pop_back();
        }

        if (rightPar > leftPar)
        {
            curr.push_back(')');
            generate(curr, leftPar, rightPar - 1);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n)
    {
        string s;
        generate(s, n, n);
        return all_parenthesis;
    }
};