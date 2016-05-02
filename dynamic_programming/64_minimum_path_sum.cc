//
// Created by Neptune on 5/2/16.
//

/*
 * Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes
 * the sum of all numbers along its path.
 *
 * Note: You can only move either down or right at any point in time.
 *
 * Subscribe to see which companies asked this question
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
  public:
    int minPathSum(vector<vector<int>> &grid) {
        int m = grid.size();

        if (m == 0) return 0;

        int n = grid[0].size();

        if (n == 0) return 0;

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];

        for (int i = 1; i < m; ++i) dp[i][0] = dp[i - 1][0] + grid[i][0];

        for (int j = 1; j < n; ++j) dp[0][j] = dp[0][j - 1] + grid[0][j]; ;

        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);

        return dp[m - 1][n - 1];
    }
};

int main() {
    vector<vector<int>> grid{
        {1, 2},
        {1, 1}
        //{1,2,3,4},
        //{1,2,3,4},
        //{1,2,3,4},
        //{1,2,3,4},
    };
    cout << Solution().minPathSum(grid) << endl;
    return 0;
}
