//
// Created by Neptune on 5/2/16.
//

/*
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 *
 * For example,
 *      "A man, a plan, a canal: Panama" is a palindrome.
 *      "race a car" is not a palindrome.
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1;

        while (l < r) {
            while (!(isalpha(s[l]) || isnumber(s[l]))  && l < r)
                l++;

            while (!(isalpha(s[r]) || isnumber(s[r])) && l < r)
                r--;

            if (l >= r)
                break;

            if (tolower(s[l++]) != tolower(s[r--]))
                return false;
        }

        return true;
    }
};

int main() {
    cout << Solution().isPalindrome("race a car") << endl;
    cout << Solution().isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << Solution().isPalindrome("0P") << endl;
    return 0;
}
