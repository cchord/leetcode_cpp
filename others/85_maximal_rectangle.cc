//
// Created by Neptune on 4/25/16.
//

/*
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return
 * its area.
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
  public:
    int maximalRectangle(vector <vector<char>> &matrix) {
        // solve one line by one line - looks like DP
        int m = matrix.size();

        if (m == 0) return 0;

        int n = matrix[0].size();
        int maxArea = 0;
        int leftBound[n], rightBound[n], height[n];
        fill_n(leftBound, n, 0);
        fill_n(rightBound, n, n);
        fill_n(height, n, 0);

        for (int i = 0; i < m; ++i) {
            // 1. calculate height
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '0')
                    height[j] = 0;
                else
                    height[j]++;
            }

            // 2. calculate leftBound
            int currLeftBound = 0;

            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '0') {
                    leftBound[j] = 0;
                    currLeftBound = j + 1;
                } else
                    leftBound[j] = max(leftBound[j], currLeftBound);
            }

            // 3. calculate rightBound
            int currRightBound = n;

            for (int j = n - 1; j >= 0; --j) {
                if (matrix[i][j] == '0') {
                    rightBound[j] = n;
                    currRightBound = j;
                } else
                    rightBound[j] = min(rightBound[j], currRightBound);
            }

            // calculate area
            for (int j = 0; j < n; ++j)
                maxArea = max(maxArea, (rightBound[j] - leftBound[j]) * height[j]);
        }

        return maxArea;
    }
};

int main() {
    vector<vector<char>> matrix{
        {'0', '0', '0', '1', '0', '0'},
        {'0', '0', '1', '1', '0', '0'},
        {'0', '0', '1', '1', '1', '1'},
        {'0', '1', '1', '1', '1', '1'},
    };
    cout << Solution().maximalRectangle(matrix) << endl;
    return 0;
}
