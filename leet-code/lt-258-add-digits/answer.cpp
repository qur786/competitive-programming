#include <bits/stdc++.h>

using namespace std;

/**
 * Time complexity: O(1)
 * Space complexity: O(1)
 */

class Solution
{
public:
    int addDigits(int num)
    {
        /*
        METHOD 1:
         * Time complexity: O(log(number of digits of num) * log(value of temp))
         * Space complexity: O(1)

        while (num > 9) {
            int temp = num;
            int sum = 0;
            while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
            }

            num = sum;
        }

        return num;
        */

        if (num == 0)
        {
            return 0;
        }
        return 1 + (num - 1) % 9; // Digital Root formula
    }
};