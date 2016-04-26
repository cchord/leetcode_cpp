//
// Created by Neptune on 4/26/16.
//

/*
 * Given a list of non negative integers, arrange them such that they form the largest number.
 *
 * For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
 *
 * Note: The result may be very large, so you need to return a string instead of an integer.
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
  public:
    string largestNumber(vector<int> &nums) {
        if (nums.size() == 0) return "";

        vector<string> strs;
        strs.resize(nums.size());
        transform(nums.begin(), nums.end(), strs.begin(), [](int n) {
            return to_string(n);
        });
        // sort criteria can be more complicated than just less/greater
        sort(strs.begin(), strs.end(), [](string & s1, string & s2) -> bool {
            return s1 + s2 > s2 + s1;
        });

        if (strs[0] == "0")
            return "0";

        return accumulate(strs.begin(), strs.end(), string(""));
    }
};

int main() {
    vector<int> nums{1, 203, 2};
    cout << Solution().largestNumber(nums) << endl;
    return 0;
}
