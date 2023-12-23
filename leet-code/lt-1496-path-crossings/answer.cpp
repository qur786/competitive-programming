#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isPathCrossing(string path)
    {
        map<pair<int, int>, int> locations = {{{0, 0}, 1}};
        pair<int, int> last_pos = {0, 0};
        for (char c : path)
        {
            pair<int, int> new_pos;
            if (c == 'N')
            {
                new_pos = {last_pos.first, last_pos.second + 1};
            }
            else if (c == 'S')
            {
                new_pos = {last_pos.first, last_pos.second - 1};
            }
            else if (c == 'E')
            {
                new_pos = {last_pos.first + 1, last_pos.second};
            }
            else
            {
                new_pos = {last_pos.first - 1, last_pos.second};
            }

            if (locations[new_pos] == 1)
            {
                return true;
            }
            locations[new_pos] = 1;
            last_pos = new_pos;
        }

        return false;
    }
};