//
// Created by Neptune on 4/23/16.
//

/* Given n non - negative integers a1, a2, ..., an, where each represents a point at coordinate(i, ai).
 * n vertical lines are drawn such that the two endpoints of line i is at(i, ai) and (i, 0). Find two lines,
 * which together with x - axis forms a container, such that the container contains the most water.
 * Note: You may not slant the container.*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        int maxArea(vector<int> &height) {
            int n = height.size();

            if (n == 0)
                return 0;

            int maximum = 0, l = 0, r = n - 1;

            while (l < r) {
                maximum = max(maximum, min(height[l], height[r]) * (r - l));

                if (height[l] < height[r])
                    l++;
                else
                    r--;
            }

            return maximum;
        }
};

int main() {
    vector<int> v{1, 2, 3, 5, 6};
    cout << Solution().maxArea(v) << endl;
    vector<int> v2{1, 1};
    cout << Solution().maxArea(v2) << endl;
}
