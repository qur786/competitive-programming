#include <bits/stdc++.h>

using namespace std;

/**
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

class Solution
{
public:
    string makeGood(string s)
    {
        stack<char> st;
        string result;

        if (s.size() <= 1)
        {
            return s;
        }

        for (int i = s.size() - 1; i >= 0; i--)
        {
            st.push(s[i]);
        }

        while (!st.empty())
        {
            char last_char = st.top();
            st.pop();
            if (result.empty())
            {
                result.push_back(last_char);
            }
            else
            {
                char last_res_char = result.back();
                if ((isupper(last_res_char) ^ isupper(last_char)) &&
                    (toupper(last_res_char) == toupper(last_char)))
                {
                    result.pop_back();
                }
                else
                {
                    result.push_back(last_char);
                }
            }
        }

        return result;
    }
};