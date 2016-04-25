//
// Created by Neptune on 4/25/16.
//

/*
 * Given a string S and a string T, find the minimum window in S which will contain all the characters in T
 * in complexity O(n).
 *
 * For example,
 *      S = "ADOBECODEBANC"
 *      T = "ABC"
 *
 * Minimum window is "BANC".
 * Note:
 *      If there is no such window in S that covers all characters in T, return the empty string "".
 * If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window
 * in S.
 */

#include <string>
#include <unordered_map>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
  public:
    string minWindow(string s, string t) {
        unordered_map<char, int> map;
        int sLen = s.length();
        int l = 0, r = 0, minLen = INT_MAX, minStart = 0, count = 0;

        for (auto &c : t) {
            map[c]++;
            count++;
        }

        while (r < sLen) {
            if (map[s[r++]]-- > 0)
                count--;

            while (count == 0) {
                auto len = r - l;

                if (len < minLen) {
                    minLen = len;
                    minStart = l;
                }

                if (map[s[l++]]++ == 0)
                    count++;
            }
        }

        return  minLen == INT_MAX ?  "" : s.substr(minStart, minLen);
    }
};

int main() {
    string S = "ADOBECODEBANC";
    string T = "ABCG";
    Solution s;
    cout << s.minWindow(S, T) << endl;
    T = "ABC";
    cout << s.minWindow(S, T) << endl;
    T = "";
    cout << s.minWindow(S, T) << endl;
    return 0;
}
