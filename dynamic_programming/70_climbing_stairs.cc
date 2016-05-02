//
// Created by Neptune on 5/2/16.
//

/*
 * You are climbing a stair case. It takes n steps to reach to the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 */

#include <iostream>

using namespace std;

class Solution {
  public:
    int climbStairs(int n) {
        if (n <= 0) return 0;

        if (n == 1) return 1;

        if (n == 2) return 2;

        int prev1 = 1, prev2 = 2;
        int res = 0;

        for (int i = 3; i <= n; ++i) {
            res = prev1 + prev2;
            prev1 = prev2;
            prev2 = res;
        }

        return res;
    }
};

int main() {
    cout << Solution().climbStairs(10) << endl;
    return 0;
}
