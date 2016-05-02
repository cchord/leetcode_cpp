//
// Created by Neptune on 5/2/16.
//

/*
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
 *
 * For example,
 *
 * Given:
 *      s1 = "aabcc",
 *      s2 = "dbbca",
 *      When s3 = "aadbbcbcac", return true.
 *      When s3 = "aadbbbaccc", return false.
 */

#include <string>
#include <iostream>

using namespace std;

class Solution {
  public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();

        if (len1 + len2 != len3) return false;

        bool dp[len1 + 1][len2 + 1];

        for (int i = 0; i <= len1; ++i)
            for (int j = 0; j <= len2; ++j) {
                if (i == 0 && j == 0)
                    dp[i][j] = true;
                else if (i == 0)
                    dp[i][j] = dp[i][j - 1] && s2[j - 1] == s3[i + j - 1];
                else if (j == 0)
                    dp[i][j] = dp[i - 1][j] && s1[i - 1] == s3[i + j - 1];
                else
                    dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
                               (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }

        return dp[len1][len2];
    }
};

int main() {
    cout << Solution().isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
    return 0;
}
