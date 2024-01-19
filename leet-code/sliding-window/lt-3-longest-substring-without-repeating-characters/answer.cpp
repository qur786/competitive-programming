#include <bits/stdc++.h>

using namespace std;

/**
 * Time complexity: O(n)
 * Space complexity: O(min(m, n)) where m is the character set and n is the no of unique characters in the string
 */

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.empty())
        {
            return 0;
        }

        unordered_map<char, int> lastIndexMap;
        int longestSubstring = 0;
        int currentSubstring = 0;
        int startIndex = 0;

        int i = 0;
        while (i < s.size())
        {
            if (lastIndexMap.find(s[i]) != lastIndexMap.end() &&
                lastIndexMap[s[i]] >= startIndex)
            {
                startIndex = lastIndexMap[s[i]] + 1;
                currentSubstring = i - startIndex;
            }
            lastIndexMap[s[i]] = i;
            currentSubstring++;
            longestSubstring = max(longestSubstring, currentSubstring);
            i++;
        }

        return longestSubstring;
    }
};