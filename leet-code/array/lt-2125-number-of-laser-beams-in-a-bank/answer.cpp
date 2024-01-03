#include <bits/stdc++.h>

using namespace std;

/**
 * Time complexity: O(m * n)
 * Space complexity: O(1)
 */

class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        int totalBeams = 0, currDev = 0, nextDev = 0;
        for (int i = 0; i < bank.size(); i++)
        {
            nextDev = count(bank[i].begin(), bank[i].end(), '1');
            if (nextDev > 0)
            {
                totalBeams += currDev * nextDev;
                currDev = nextDev;
                nextDev = 0;
            }
        }
        return totalBeams;
    }
};