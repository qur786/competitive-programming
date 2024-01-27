#include <bits/stdc++.h>

using namespace std;

/**
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        stack<char> st;
        unordered_set<char> seen;
        vector<int> last_index(26, -1);

        for (int i = 0; i < s.size(); i++)
        {
            last_index[s[i] - 'a'] = i;
        }

        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (seen.count(c))
            {
                continue;
            }

            while (!st.empty() && c < st.top() && last_index[st.top() - 'a'] > i)
            {
                seen.erase(st.top());
                st.pop();
            }

            st.push(c);
            seen.insert(c);
        }

        string result = "";
        while (!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};