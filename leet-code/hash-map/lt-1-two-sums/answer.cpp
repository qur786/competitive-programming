#include <bits/stdc++.h>

using namespace std;

/**
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> num_index_map;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++)
        {
            if (num_index_map.find(target - nums[i]) != num_index_map.end())
            {
                result.push_back(num_index_map[target - nums[i]]);
                result.push_back(i);
                break;
            }
            else
            {
                num_index_map[nums[i]] = i;
            }
        }

        return result;
    }
};