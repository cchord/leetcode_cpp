//
// Created by Neptune on 4/26/16.
//

/*
 * Given two strings s and t, write a function to determine if t is an anagram of s.
 *
 * For example,
 *         s = "anagram", t = "nagaram", return true.
 *         s = "rat", t = "car", return false.
 */

#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

class Solution {
  public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> map;

        for (auto &c : s)
            map[c]++;

        for (auto &c : t) {
            if (map.find(c) == map.end())
                return false;

            if (--map[c] == 0)
                map.erase(c);
        }

        return map.size() == 0;
    }
};

int main() {
    cout << Solution().isAnagram("abc", "cae") << endl;
    return 0;
}
