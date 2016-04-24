//
// Created by Neptune on 4/23/16.
//

/*
 * Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
 * For example,
 * Given n = 3, there are a total of 5 unique BST's.
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
  public:
    int numTrees(int n) {
        if (n == 0)
            return 0;

        vector<int> vec(n + 1, 0);
        vec[0] = vec[1] = 1;

        for (int i = 2; i < n + 1; i++) {
            for (int j = 0; j < i; j++)
                vec[i] += vec[j] * vec[i - j - 1];
        }

        return vec[n];
    }
};

int main() {
    cout << Solution().numTrees(3) << endl;
    cout << Solution().numTrees(2) << endl;
    cout << Solution().numTrees(1) << endl;
    return 0;
}
