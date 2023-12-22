class Solution {
public:
    int maxScore(string s) {
        /*
        METHOD 1: My Method with 7 ms submission time and 14.73% beats.
        Time complexity: O(n^2)
        Space complexity: O(1)

        string::iterator citr;
        int maxScore = 0;
        for (citr = s.begin(); citr != s.end() - 1; citr++) {
            int zeros = count(s.begin(), citr + 1, '0');
            int ones = count(citr + 1, s.end(), '1');
            int score = zeros + ones;
            maxScore = score > maxScore ? score : maxScore;
        }
        return maxScore;
        */

        /*
        METHOD 2: From users, with 0 ms submission and 100% beats
        Time complexity: O(n)
        Space complexity: O(1)
        */


        int zeros = 0, ones = 0;
        int maxScore = 0;
        ones = count(s.begin(), s.end(), '1');
        for (int i = 0; i < s.size() - 1; i++) {
            zeros += s[i] == '0' ? 1 : 0;
            ones -= s[i] == '1' ? 1 : 0;
            maxScore = max(maxScore, zeros+ones);
        }

        return maxScore;
    }
};