//
// Created by Neptune on 5/2/16.
//

/*
 * Given a string S and a string T, count the number of distinct subsequences of T in S.
 *
 * A subsequence of a string is a new string which is formed from the original string by deleting some
 * (can be none) of the characters without disturbing the relative positions of the remaining characters.
 * (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
 *
 * Here is an example:
 *      S = "rabbbit", T = "rabbit"
 * Return 3.
 */

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:

    /*
     * As a typical way to implement a dynamic programming algorithm, we construct a matrix dp, where each cell
     * dp[i][j] represents the number of solutions of aligning substring T[0..i] with S[0..j];
     *
     * Rule 1). dp[0][j] = 1, since aligning T = "" with any substring of S would have only ONE solution which is
     * to delete all characters in S.
     *
     * Rule 2). when i > 0, dp[i][j] can be derived by two cases:
     *      case 1). if T[i] != S[j], then the solution would be to ignore the character S[j] and align substring
     * T[0..i] with S[0..(j-1)]. Therefore, dp[i][j] = dp[i][j-1].
     *      case 2). if T[i] == S[j], then first we could adopt the solution in case 1), but also we could match the
     * characters T[i] and S[j] and align the rest of them (i.e. T[0..(i-1)] and S[0..(j-1)].
     * As a result, dp[i][j] = dp[i][j-1] + d[i-1][j-1]
     *
     * e.g. T = B, S = ABC
     * dp[1][2]=1: Align T'=B and S'=AB, only one solution, which is to remove character A in S'.
     */
    int numDistinct(string s, string t) {
        int lens = s.length(), lent = t.length();

        if (lens == 0 || lent > lens) return 0;

        vector<vector<int>> dp(lent + 1, vector<int>(lens + 1, 0));

        for (int i = 0; i <= lens; ++i)
            dp[0][i] = 1;

        for (int i = 1; i <= lent; ++i)
            for (int j = 1; j <= lens; ++j) {
                if (t[i - 1] != s[j - 1])
                    dp[i][j] = dp[i][j - 1];
                else
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
            }

        return dp[lent][lens];
    }
};

int main() {
    cout << Solution().numDistinct("rabbbit", "rabbit") << endl;
    cout << Solution().numDistinct("b", "a") << endl;
    return 0;
}
