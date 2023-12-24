#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }

        unordered_map<char, char> char_map1, char_map2;
        for (int i = 0; i < s.size(); i++)
        {
            if (char_map1[s[i]] && (char_map1[s[i]] != t[i]))
            {
                return false;
            }
            else if (char_map2[t[i]] && (char_map2[t[i]] != s[i]))
            {
                return false;
            }
            else
            {
                char_map1[s[i]] = t[i];
                char_map2[t[i]] = s[i];
            }
        }

        return true;
    }
};