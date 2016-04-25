//
// Created by Neptune on 4/25/16.
//

/*
 * Given an array of strings, group anagrams together.
 */
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    vector <vector<string>> groupAnagrams(vector <string> &strs) {
        //
        // !!!map<char, int> cannot be used as KEY in hash table!!!
        //
        //unordered_map<map<char, int>, vector<string>> resultMap;
        unordered_map<string, vector<string>> resultMap;

        for (auto s : strs) {
            auto copy(s);
            sort(copy.begin(), copy.end());
            resultMap[copy].push_back(s);
        }

        vector<vector<string>> res;

        for (auto &pair : resultMap) {
            sort(pair.second.begin(), pair.second.end());
            res.push_back(pair.second);
        }

        return res;
    }
};

int main() {
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    auto res = Solution().groupAnagrams(strs);

    for (auto &vec : res) {
        for (auto &s : vec)
            cout << s << " ";

        cout << endl;
    }

    return 0;
}

