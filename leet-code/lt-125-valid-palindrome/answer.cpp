#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        /*
        Method 1: my method
        Runtime: 99ms
        Beats: 5%
        Time complexity: O(n)
        Space complexity: O(n)

        regex r("[^a-zA-Z0-9]");
        string strippedStr = regex_replace(s, r, "");
        transform(strippedStr.begin(), strippedStr.end(), strippedStr.begin(), ::toupper);
        string reverseStr = strippedStr;
        reverse(reverseStr.begin(), reverseStr.end());
        return reverseStr == strippedStr;
        */

        /*
        Method 2: Users' method
        Runtime: 2ms
        Beats: 93.06%
        Time complexity: O(n)
        Space complexity: O(1)
        */

        int start = 0, end = s.size() - 1;
        while (start <= end)
        {
            if (isalnum(s[start]) == false)
            {
                start++;
                continue;
            }
            if (isalnum(s[end]) == false)
            {
                end--;
                continue;
            }
            if (tolower(s[start]) != tolower(s[end]))
            {
                return false;
            }
            else
            {
                start++;
                end--;
            }
        }
        return true;
    }
};