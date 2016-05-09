//
// Created by Neptune on 5/9/16.
//

/*
 * The thief has found himself a new place for his thievery again. There is only one entrance to this area,
 * called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart
 * thief realized that "all houses in this place forms a binary tree". It will automatically contact the police
 * if two directly-linked houses were broken into on the same night.
 *
 * Determine the maximum amount of money the thief can rob tonight without alerting the police.
 *
 * Example 1:
 *             3
 *            / \
 *           2   3
 *            \   \
 *             3   1
 * Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
 *
 * Example 2:
 *             3
 *            / \
 *           4   5
 *          / \   \
 *         1   3   1
 *
 * Maximum amount of money the thief can rob = 4 + 5 = 9.
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
    int rob(TreeNode *root) {
        auto res = dp(root);
        return max(res.first, res.second);
    }

  private:
    // first: max value robbing this node, second: max value not robbing this node
    pair<int, int> dp(TreeNode *node) {
        if (!node) return {0, 0};

        auto left = dp(node->left);

        auto right = dp(node->right);

        return {node->val + left.second + right.second,
                max(left.first, left.second) + max(right.first, right.second)};
    }
};

int main() {
    TreeNode *t = new TreeNode(3);
    t->left = new TreeNode(2);
    t->left->right = new TreeNode(3);
    t->right = new TreeNode(3);
    t->right->right = new TreeNode(1);
    cout << Solution().rob(t) << endl;
    return 0;
}
