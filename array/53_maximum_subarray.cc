//
// Created by Neptune on 4/28/16.
//

/*
 * Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 *
 * For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
 * the contiguous subarray [4,−1,2,1] has the largest sum = 6.
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
  public:

    #if 0
    // DC
    int maxSubArray(vector<int> &nums) {
        if (nums.size() == 0)
            return 0;

        int max, lmax, rmax, sum;
        maxSubArray(nums, 0, nums.size() - 1, max, lmax, rmax, sum);
        return max;
    }

    void maxSubArray(vector<int> &nums, int l, int r, int &max, int &lmax, int &rmax, int &sum) {
        if (l == r)
            max = lmax = rmax = sum = nums[l];
        else {
            int mid = (l + r) / 2;
            int max1, lmax1, rmax1, sum1, max2, lmax2, rmax2, sum2;
            maxSubArray(nums, l, mid, max1, lmax1, rmax1, sum1);
            maxSubArray(nums, mid + 1, r, max2, lmax2, rmax2, sum2);
            max = std::max(std::max(max1, max2), rmax1 + lmax2);
            lmax = std::max(lmax1, sum1 + lmax2);
            rmax = std::max(rmax2, sum2 + rmax1);
            sum = sum1 + sum2;
        }
    }
    #else
    int maxSubArray(vector<int> &nums) {
        int currentSum = 0, maxSum = numeric_limits<int>::min();
        int size = nums.size();

        for (int i = 0; i < size; ++i) {
            if (currentSum < 0)
                currentSum = 0;

            currentSum += nums[i];
            maxSum = max(currentSum, maxSum);
        }

        return maxSum;
    }

    #endif
};

int main() {
    vector<int> v{0, 1, -8, 10};
    cout << Solution().maxSubArray(v) << endl;
    return 0;
}

