//
// Created by Neptune on 5/9/16.
//

/*
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 *
 * An example is the root-to-leaf path 1->2->3 which represents the number 123.
 *
 * Find the total sum of all root-to-leaf numbers.
 *
 * For example,
 *
 *
 *      1
 *     / \
 *    2   3
 * The root-to-leaf path 1->2 represents the number 12.
 * The root-to-leaf path 1->3 represents the number 13.
 *
 * Return the sum = 12 + 13 = 25.
 */

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
};

class Solution {
  public:
    int sumNumbers(TreeNode *root) {
        int sum = 0;
        dfs(root, sum, 0);
        return sum;
    }

    void dfs(TreeNode *node, int &sum, int num) {
        if (!node) return;

        num += node->val;

        if (!node->left && !node->right) {
            sum += num;
            return;
        }

        if (node->left) dfs(node->left, sum, num * 10);

        if (node->right) dfs(node->right, sum, num * 10);
    }
};

int main() {
    TreeNode *t = new TreeNode(1);
    t->left = new TreeNode(2);
    t->right = new TreeNode(3);
    t->left->left = new TreeNode(4);
    t->right->right = new TreeNode(5);
    cout << Solution().sumNumbers(t) << endl;
    return 0;
}
