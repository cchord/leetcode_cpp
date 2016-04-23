//
// Created by Neptune on 4/23/16.
//

/*
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution.
 * Example:
 *      Given nums = [2, 7, 11, 15], target = 9,
 *      Because nums[0] + nums[1] = 2 + 7 = 9,
 *      return [0, 1].
 */
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); ++i) {
            if (map.find(target - nums[i]) != map.end()) {
                vector<int> res{i, map[target - nums[i]]};
                sort(res.begin(), res.end());
                return res;
            } else
                map.emplace(nums[i], i);
        }

        return vector<int> { -1, -1};
    }
};

int main() {
    vector<int> v({2, 7, 11, 15});
    auto res = Solution().twoSum(v, 90);

    for (auto n : res)
        cout << n << " ";

    return 0;
}
