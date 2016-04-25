//
// Created by Neptune on 4/25/16.
//

/*
 * Given a string, find the length of the longest substring without repeating characters.
 * Examples:
 *      Given "abcabcbb", the answer is "abc", which the length is 3.
 *      Given "bbbbb", the answer is "b", with the length of 1.
 *      Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring,
 *      "pwke" is a subsequence and not a substring.
 */

#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        auto sz = s.size();
        unordered_map<char, int> map;
        int start = 0, maxLen = 0;

        for (auto i = 0; i < sz; ++i) {
            auto c = s[i];

            if (map.find(c) != map.end())
                start = max(start, map[c] + 1);

            map[c] = i;
            maxLen = max(maxLen, i - start + 1);
        }

        return maxLen;
    }
};

int main() {
    string s = "qwnfenpglqdq";
    cout << Solution().lengthOfLongestSubstring(s) << endl;
    return 0;
}
