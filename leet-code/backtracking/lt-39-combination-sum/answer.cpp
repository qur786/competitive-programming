#include <bits/stdc++.h>

using namespace std;

/**
 * Time complexity: O(k * 2^n), where 'k' is the number of valid combinations.
 * Space complexity: O(n)
 */

class Solution
{
public:
    vector<vector<int>> combinations;
    void generateSum(vector<int> &candidates, vector<int> &curr_combination,
                     int target, int index)
    {
        if (target == 0)
        {
            combinations.push_back(curr_combination);
            return;
        }
        // Explore combinations using elements from the current index onwards
        for (int i = index; i < candidates.size(); ++i)
        {
            // Check if the current element doesn't exceed the target
            if (candidates[i] <= target)
            {
                curr_combination.push_back(candidates[i]);
                // Recursively call generateSum with updated target and index
                generateSum(candidates, curr_combination,
                            target - candidates[i],
                            i);
                curr_combination.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> curr_combination;
        generateSum(candidates, curr_combination, target, 0);
        return combinations;
    }
};