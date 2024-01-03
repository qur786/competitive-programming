#include <bits/stdc++.h>

using namespace std;

/**
 * Time complexity: O(2^n)
 * Space complexity: O(2^n)
 */

class Solution
{
public:
    vector<vector<int>> sets;
    void generateSubsets(vector<int> &subset, int index, vector<int> &nums)
    {
        if (index == nums.size())
        {
            sets.push_back(subset);
            return;
        }

        generateSubsets(subset, index + 1, nums);

        subset.push_back(nums[index]);

        generateSubsets(subset, index + 1, nums);

        subset.pop_back();
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> subset;
        generateSubsets(subset, 0, nums);
        return sets;
    }
};