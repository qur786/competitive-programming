#include <bits/stdc++.h>

using namespace std;

/**
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

class Solution
{
public:
    string simplifyPath(string path)
    {
        string token;
        stringstream ss(path);
        stack<string> s;
        string result;
        while (std::getline(ss, token, '/'))
        {
            if (token != "")
            {
                if (token == "..")
                {
                    if (!s.empty())
                    {
                        s.pop();
                    }
                }
                else if (token != ".")
                {
                    s.emplace(token);
                }
            }
        }

        while (!s.empty())
        {
            result = '/' + s.top() + result;
            s.pop();
        }

        return result.empty() ? "/" : result;
    }
};