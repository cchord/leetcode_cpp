//
// Created by Neptune on 5/9/16.
//

/*
 * Given a binary tree, find the maximum path sum.
 *
 * For this problem, a path is defined as any sequence of nodes from some starting node to any node in the
 * tree along the parent-child connections. The path does not need to go through the root.
 *
 * For example:
 *      Given the below binary tree,
 *               1
 *              / \
 *             2   3
 *      Return 6.
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
    int maxPathSum(TreeNode *root) {
        if (!root) return 0;

        int maxSum = numeric_limits<int>::min();
        maxPathSum(root, maxSum);
        return maxSum;
    }

    // first: the max of left and right path, second: the path sum of current subtree including the root node
    pair<int, int> maxPathSum(TreeNode *root, int &maxSum) {
        if (!root) return {0, 0};

        auto left = maxPathSum(root->left, maxSum);

        auto right = maxPathSum(root->right, maxSum);

        pair<int, int> p(root->val + max(0, max(left.first, right.first)),
                         (left.first > 0 ? left.first : 0) +
                         (right.first > 0 ? right.first : 0) + root->val);

        //maxSum = max(maxSum, max(p.first, p.second));
        maxSum = max(maxSum, p.second);

        return p;
    };
};

int main() {
    TreeNode *t = new TreeNode(-10);
    t->left = new TreeNode(-2);
    t->right = new TreeNode(-3);
    t->left->left = new TreeNode(-4);
    t->left->right = new TreeNode(8);
    t->right->right = new TreeNode(5);
    cout << Solution().maxPathSum(t) << endl;
    cout << endl;
    return 0;
}
