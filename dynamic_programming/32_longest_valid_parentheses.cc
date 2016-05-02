//
// Created by Neptune on 5/2/16.
//

/*
 * Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed)
 * parentheses substring.
 *
 * For "(()", the longest valid parentheses substring is "()", which has length = 2.
 *
 * Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
 */

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    #if 0
    // stack based solution
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        int maxLen = 0;

        for (int i = 0; i < s.size(); ++i) {
            int t = stk.top();

            if (t != -1 && s[i] == ')' && s[t] == '(') {
                stk.pop();
                maxLen = max(maxLen, i - stk.top());
            } else
                stk.push(i);
        }

        return maxLen;
    }
    #else
    // DP - dp[i+1] stores the longest valid one at ith pos
    int longestValidParentheses(string s) {
        int len = s.size(), res = 0;
        vector<int> dp(len + 1, 0);

        for (int i = 0; i < len; ++i) {
            if (s[i] == ')') {
                int left = i - dp[i] - 1;

                if (left >= 0 && s[left] == '(')
                    dp[i + 1] = dp[i] + 2 + dp[left];

                res = max(res, dp[i + 1]);
            }
        }

        return res;
    }
    #endif
};

int main() {
    cout << Solution().longestValidParentheses("(((((((()))") << endl;
    return 0;
}
