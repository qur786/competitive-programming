#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        /*
        METHOD 1:
        Time complexity: O(log n)
        Space complexity: O(log n)

        if (n == 1 || n == 2) {
            return true;
        } else if (n % 2 == 1 || n == 0) {
            return false;
        } else {
            return isPowerOfTwo(n / 2);
        }
        return true;
        */

        /**
         * METHOD 2:
         * Time complexity: O(1)
         * Space complexity: O(1)
         */
        return n > 0 && (n & (n - 1)) == 0;
    }
};