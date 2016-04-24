//
// Created by Neptune on 4/23/16.
//

/*
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
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
    bool isSymmetric(TreeNode *root) {
        if (!root)
            return true;

        return isSymmetric(root->left, root->right);
    }

    bool isSymmetric(TreeNode *left, TreeNode *right) {
        if (!left && !right)
            return true;

        if ((!left || !right) || left->val != right->val)
            return false;

        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    cout << Solution().isSymmetric(root) << endl;
    return 0;
}

