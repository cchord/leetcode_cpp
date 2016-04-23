//
// Created by Neptune on 4/23/16.
//
/* Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water
 * it is able to trap after raining.
 * For example,
 *      Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        int trap(vector<int> &height) {
            int n = height.size();
            int bar = 0, base = 0, l = 0, r = n - 1, total = 0;

            while (l < r) {
                bar  = max(bar, max(height[l], height[r]));
                base = max(base, min(height[l], height[r]));
                total += base - min(height[l], height[r]);

                if (height[l] < height[r])
                    l++;
                else
                    r--;
            }

            return total;
        }
};

int main() {
    vector<int> v{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << Solution().trap(v) << endl;
    return 0;
}
