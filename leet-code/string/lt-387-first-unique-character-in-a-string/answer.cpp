#include <bits/stdc++.h>

using namespace std;

/**
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

class Solution
{
public:
    int firstUniqChar(string s)
    {
        int char_count[26]; // To contain the count of chars

        for (const char &c : s)
        {
            char_count[c - 'a'] += 1;
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (char_count[s[i] - 'a'] == 1)
            {
                return i;
            }
        }

        return -1;
    }
};