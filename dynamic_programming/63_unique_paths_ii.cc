//
// Created by Neptune on 5/2/16.
//

/*
 * Follow up for "Unique Paths":
 *
 * Now consider if some obstacles are added to the grids. How many unique paths would there be?
 *
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 *
 * For example,
 *      There is one obstacle in the middle of a 3x3 grid as illustrated below.
 *
 *      [
 *          [0,0,0],
 *          [0,1,0],
 *          [0,0,0]
 *      ]
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int uniquePathsWithObstacles(vector <vector<int>> &obstacleGrid) {
        int m = obstacleGrid.size();

        if (m == 0) return 0;

        int n = obstacleGrid[0].size();

        if (n == 0) return 0;

        int dp[m][n];
        int pathNum = 1;

        for (int i = 0; i < m; ++i) {
            pathNum = (obstacleGrid[i][0] == 1) ? 0 : pathNum;
            dp[i][0] = pathNum;
        }

        pathNum = 1;

        for (int j = 0; j < n; ++j) {
            pathNum = (obstacleGrid[0][j] == 1) ? 0 : pathNum;
            dp[0][j] = pathNum;
        }

        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                dp[i][j] = (obstacleGrid[i][j] == 1) ? 0 : dp[i - 1][j] + dp[i][j - 1];

        return dp[m - 1][n - 1];
    }
};

int main() {
    vector<vector<int>> grid{
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    cout << Solution().uniquePathsWithObstacles(grid) << endl;
    return 0;
}
