//
// Created by Neptune on 5/2/16.
//

/*
 * Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which
 * the sum ≥ s. If there isn't one, return 0 instead.
 *
 * For example, given the array [2,3,1,2,4,3] and s = 7,
 *      the subarray [4,3] has the minimal length under the problem constraint.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int minSubArrayLen(int s, vector<int> &nums) {
        int minLen = numeric_limits<int>::max();
        int l = 0, r = 0, size = nums.size();
        int sum = 0;

        while (r < size) {
            sum += nums[r];

            while (sum >= s && l <= r) {
                minLen = min(minLen, r - l + 1);
                sum -= nums[l++];
            }

            r++;
        }

        return minLen == numeric_limits<int>::max() ? 0 : minLen;
    }
};

int main() {
    vector<int> v{2, 3, 1, 2, 4, 3};
    cout << Solution().minSubArrayLen(7, v) << endl;
    return 0;
}
