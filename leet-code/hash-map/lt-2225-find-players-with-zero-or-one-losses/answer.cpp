#include <bits/stdc++.h>

using namespace std;

/**
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        unordered_map<int, int> players_score;
        set<int> no_loses;
        set<int> one_lose;

        for (vector<int> &m : matches)
        {
            players_score[m[1]] += 1;
        }

        for (vector<int> &m : matches)
        {
            if (!players_score[m[0]])
            {
                no_loses.insert(m[0]);
            }

            if (players_score[m[1]] == 1)
            {
                one_lose.insert(m[1]);
            }
        }

        vector<vector<int>> result;
        result.emplace_back(no_loses.begin(), no_loses.end());
        result.emplace_back(one_lose.begin(), one_lose.end());

        return result;
    }
};