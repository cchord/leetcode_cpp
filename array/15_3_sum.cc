//
// Created by Neptune on 4/23/16.
//
/*
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
 * Find all unique triplets in the array which gives the sum of zero.
 * Note:
 *      Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 *      The solution set must not contain duplicate triplets.
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    // two pointers
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        int n = nums.size();

        if (n == 0)
            return res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue; // avoid duplicates

            for (int j = i + 1, k = n - 1; j < k;) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum == 0) {
                    // make sure sum is 0, then skip the duplicates...
                    res.push_back(vector<int>({nums[i], nums[j], nums[k]}));

                    while (j < k && nums[j] == nums[j + 1]) j++; // skip same results

                    while (j < k && nums[k] == nums[k - 1]) k--; // skip same results

                    j++, k--;
                } else if (sum < 0) // sum is too small
                    j++;
                else
                    k--;
            }
        }

        return res;
    }
};

int main() {
    vector<int> v{ -1, -5, 2, 3, 4, 10, -8, -6, 6, -2};
    auto res = Solution().threeSum(v);

    for (auto &vec : res) {
        for (auto n : vec)
            cout << n << " ";

        cout << endl;
    }

    return 0;
}
