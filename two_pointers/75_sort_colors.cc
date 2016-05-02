//
// Created by Neptune on 5/2/16.
//

/*
 * Given an array with n objects colored red, white or blue, sort them so that objects of the same color are
 * adjacent, with the colors in the order red, white and blue.
 * Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    void sortColors(vector<int> &nums) {
        // two way partition
        int i = 0, j = 0, k = nums.size() - 1;

        while (j <= k) {
            if (nums[j] == 0)
                swap(nums[i++], nums[j++]);
            else if (nums[j] == 1)
                j++;
            else if (nums[j] == 2)
                swap(nums[j], nums[k--]);
        }
    }
};

int main() {
    vector<int> v{1, 0, 0, 2, 1, 0};
    Solution().sortColors(v);

    for (auto n : v)
        cout << n << " ";

    cout << endl;
    return 0;
}

