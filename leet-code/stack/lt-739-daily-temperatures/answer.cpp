#include <bits/stdc++.h>

using namespace std;

/**
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> result(temperatures.size(), 0);
        stack<int> indices;

        for (int i = 0; i < temperatures.size(); i++)
        {
            while (indices.size() > 0 &&
                   temperatures[i] > temperatures[indices.top()])
            {
                result[indices.top()] =
                    i - indices.top(); // Calculate the no. of places between
                                       // the current temperature and the
                                       // temperature which is less than it
                indices.pop();
            }
            indices.push(i);
        }

        return result;
    }
};