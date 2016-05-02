//
// Created by Neptune on 5/2/16.
//

/*
 * Given a pattern and a string str, find if str follows the same pattern.
 *
 * Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty
 * word in str.
 *
 * Examples:
 *      pattern = "abba", str = "dog cat cat dog" should return true.
 *      pattern = "abba", str = "dog cat cat fish" should return false.
 *      pattern = "aaaa", str = "dog cat cat dog" should return false.
 *      pattern = "abba", str = "dog dog dog dog" should return false.
 */

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
  public:
    bool wordPattern(string pattern, string str) {
        vector<string> strs = split(str);
        int psize = pattern.length();
        int ssize = strs.size();

        if (psize != ssize) return false;

        unordered_map<char, string> map;
        unordered_set<string> set;

        for (int i = 0; i < psize; ++i) {
            if (map.find(pattern[i]) == map.end()) {
                if (set.count(strs[i]))
                    return false;

                map[pattern[i]] = strs[i];
                set.insert(strs[i]);
            } else {
                if (map[pattern[i]] != strs[i])
                    return false;
            }
        }

        return  true;
    }

    vector<string> split(string &s, char delim = ' ') {
        vector<string> elems;
        stringstream ss(s);
        string item;

        while (getline(ss, item, delim))
            elems.push_back(item);

        return elems;
    }
};

int main() {
    cout << Solution().wordPattern("aba", "dog cat dog ") << endl;
    cout << Solution().wordPattern("abb", "dog cat dog ") << endl;
    cout << Solution().wordPattern("abb", "dog cat cat") << endl;
    cout << Solution().wordPattern("abba", "dog dog dog dog") << endl;
    return 0;
}
