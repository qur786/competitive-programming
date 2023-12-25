#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        /**
         * Time complexity: O(n)
         * Space complexity: O(n)
         */
        unordered_map<int, int> num_dict;
        int output = 0;
        for (int num : nums)
        {
            num_dict[num] += 1;
            if (num_dict[num] > nums.size() / 2)
            {
                output = num;
                break;
            }
        }
        return output;

        /**
         * You can optimize the algorithm for finding the majority element using
         * a method called Boyer-Moore Voting Algorithm. This algorithm identifies
         * the majority element in a single pass through the array without using extra space.
         *
         * Time complexity: O(n)
         * Space complexity: O(1)
         *
         * class Solution {
            public:
                int majorityElement(vector<int>& nums) {
                    int candidate = nums[0];
                    int count = 1;

                    for (int i = 1; i < nums.size(); ++i) {
                        if (nums[i] == candidate) {
                            count++;
                        } else {
                            count--;
                            if (count == 0) {
                                candidate = nums[i];
                                count = 1;
                            }
                        }
                    }

                    return candidate;
                }
            };
        */
    }
};