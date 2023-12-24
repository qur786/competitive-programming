#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minOperations(string s)
    {
        int even_ones = 0, odd_zeros = 0, even_zeros = 0, odd_ones = 0;
        int index = 0;
        for (char c : s)
        {
            const bool isEven = index++ % 2 == 0;
            if (isEven)
            {
                if (c == '1')
                {
                    even_ones += 1;
                }
                else
                {
                    even_zeros += 1;
                }
            }
            else
            {
                if (c == '1')
                {
                    odd_ones += 1;
                }
                else
                {
                    odd_zeros += 1;
                }
            }
        }

        if ((odd_ones == even_zeros && (odd_ones + even_zeros) == s.size()) || odd_zeros == even_ones && (odd_zeros + even_ones) == s.size())
        {
            return 0;
        }
        int size = s.size();
        return min(abs(size - odd_ones - even_zeros), abs(size - odd_zeros - even_ones));
    }
};