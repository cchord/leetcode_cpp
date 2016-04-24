//
// Created by Neptune on 4/24/16.
//

/*
 * Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two
 * subtrees of every node never differ by more than 1.
 */

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    bool isBalanced(TreeNode *root) {
        return treeHeight(root) >= 0;
    }

    int treeHeight(TreeNode *root) {
        if (!root)
            return 0;

        auto lheight = treeHeight(root->left);
        auto rheight = treeHeight(root->right);

        if (lheight < 0 || rheight < 0 || abs(lheight - rheight) > 1)
            return -1;

        return 1 + max(lheight, rheight);
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    cout << Solution().isBalanced(root) << endl;
    cout << Solution().isBalanced(nullptr) << endl;
    return 0;
}
