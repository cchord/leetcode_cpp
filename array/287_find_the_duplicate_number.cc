//
// Created by Neptune on 4/23/16.
//
/*
 * Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least
 * one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.
 * Note:
 *      You must not modify the array (assume the array is read only).
 *      You must use only constant, O(1) extra space.
 *      Your runtime complexity should be less than O(n2).
 *      There is only one duplicate number in the array, but it could be repeated more than once.
 */

/*
 * For example: [1,2,4,2,2] is a list which has circle:
 *      a. head is 1 - the first element;
 *      b. 1 -> 2 -> 4
 *              ^    |
 *              |____|
 *      c. the fifth 2 is not in the list.
 *
 * Use the Floyd's Cycle Detection Algorithm to solve it.
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
  public:
    int findDuplicate(vector<int> &nums) {
        int slow = 0, fast = 0;

        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];

            if (slow == fast)
                break; // circle detected
        }

        // find the entry point
        int entryPoint = 0;

        while (true) {
            slow = nums[slow];
            entryPoint = nums[entryPoint];

            if (slow == entryPoint)
                break;
        }

        return entryPoint;
    }
};

int main() {
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 7};
    cout << Solution().findDuplicate(v) << endl;
    v = {1, 1};
    cout << Solution().findDuplicate(v) << endl;
    return 0;
}
