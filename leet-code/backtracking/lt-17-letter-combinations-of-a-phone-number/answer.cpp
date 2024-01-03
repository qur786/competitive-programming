#include <bits/stdc++.h>

using namespace std;

/**
 * Time complexity: O(4^n)
 * Space complexity: O(4^n)
 */

class Solution
{
public:
    vector<string> combinations;
    unordered_map<char, string> digit_to_letters = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };
    void generateLetterCombinations(string &digits, string &combination,
                                    int index)
    {
        if (combination.size() == digits.size())
        {
            combinations.push_back(combination);
            return;
        }

        char num = digits[index];
        for (char &c : digit_to_letters[num])
        {
            combination.push_back(c);
            generateLetterCombinations(digits, combination, index + 1);
            combination.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
        {
            return {};
        }
        string combination;
        generateLetterCombinations(digits, combination, 0);
        return combinations;
    }
};