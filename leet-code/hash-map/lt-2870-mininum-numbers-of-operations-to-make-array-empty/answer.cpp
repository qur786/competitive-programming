#include <bits/stdc++.h>

using namespace std;

/**
 * Time complexity: O(n^2)
 * Space complexity: O(n)
 */

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        unordered_map<int, int> num_map;
        int operation_count = 0;
        for (int num : nums)
        {
            num_map[num] += 1;
        }

        for (pair<const int, int> &p : num_map)
        {
            if (p.second % 3 == 0)
            {
                operation_count += p.second / 3;
            }
            else
            {
                int temp = p.second;
                while (temp > 0)
                {
                    if (temp == 1)
                    {
                        return -1;
                    }
                    else if (temp % 3 == 0)
                    {
                        operation_count += temp / 3;
                        break;
                    }
                    else
                    {
                        temp -= 2;
                        operation_count++;
                    }
                }
            }
        }

        return operation_count;
    }
};