//
// Created by Neptune on 5/2/16.
//

/*
 * Write a function that takes a string as input and reverse only the vowels of a string.
 *
 * Example 1:
 * Given s = "hello", return "holle".
 *
 * Example 2:
 * Given s = "leetcode", return "leotcede".
 */
#include <string>
#include <iostream>

using namespace std;

class Solution {
  public:
    string reverseVowels(string s) {
        int l = 0, r = s.length() - 1;

        while (l < r) {
            while (l < r && !isVowel(s[l]))
                l++;

            while (l < r && !isVowel(s[r]))
                r--;

            if (l >= r)
                break;

            swap(s[l++], s[r--]);
        }

        return s;
    }

    bool isVowel(char c) {
        return c == 'a' || c == 'A' || c == 'e' || c == 'E' ||
               c == 'i' || c == 'I' || c == 'o' || c == 'O' ||
               c == 'u' || c == 'U';
    }
};

int main() {
    cout << Solution().reverseVowels("leetcode") << endl;
    return 0;
}
