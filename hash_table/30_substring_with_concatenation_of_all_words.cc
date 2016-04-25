//
// Created by Neptune on 4/25/16.
//

/*
 * You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices
 * of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening
 * characters.
 *
 * For example, given:
 *      s: "barfoothefoobarman"
 *      words: ["foo", "bar"]
 *
 * You should return the indices: [0,9]. (order does not matter).
 */
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    vector<int> findSubstring(string s, vector<string> &words) {
        unordered_map<string, int> counts;

        for (auto &word : words)
            counts[word]++;

        int strLen = s.length(), numWords = words.size(), wordLen = words[0].length();
        vector<int> res;

        for (int i = 0; i < strLen - numWords * wordLen + 1; ++i) {
            unordered_map<string, int> seen;
            int j = 0;

            for (; j < numWords; ++j) {
                string word = s.substr(i + j * wordLen, wordLen);

                if (counts.find(word) != counts.end()) {
                    if (++seen[word] > counts[word])
                        break; // more 'word' seen than them in words
                } else
                    break;
            }

            if (j == numWords)
                res.push_back(i);
        }

        return res;
    }
};

int main() {
    string s = "cbarfoothefoobarman";
    //string s = "bar";
    vector<string> words{"foo", "bar", "the"};
    auto res = Solution().findSubstring(s, words);

    for (auto n : res)
        cout << n  << " ";

    cout << endl;
    return 0;
}
