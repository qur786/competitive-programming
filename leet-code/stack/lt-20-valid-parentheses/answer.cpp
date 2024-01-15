#include <bits/stdc++.h>

using namespace std;

/**
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        unordered_map<char, char> bracket_pairs = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'}};
        for (char c : s)
        {
            if (bracket_pairs[c])
            {
                st.push(c);
            }
            else
            {
                if (st.empty() || bracket_pairs[st.top()] != c)
                {
                    return false;
                }
                st.pop();
            }
        }

        return st.empty();
    }
};