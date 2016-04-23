//
// Created by Neptune on 4/23/16.
//

/*
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 * Assume a BST is defined as follows:
 *      1. The left subtree of a node contains only nodes with keys less than the node's key.
 *      2. The right subtree of a node contains only nodes with keys greater than the node's key.
 *      3. Both the left and right subtrees must also be binary search trees.
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
    bool isValidBST(TreeNode *root) {
        return validate(root, numeric_limits<long>::min(), numeric_limits<long>::max());
    }

    bool validate(TreeNode *node, long leftBound, long rightBound) {
        if (!node)
            return true;

        if (node->val <= leftBound || node->val >= rightBound)
            return false;

        return validate(node->left, leftBound, node->val) && validate(node->right, node->val, rightBound);
    }
};

int main() {
    Solution s;
    TreeNode *root = new TreeNode(15);
    root->left = new TreeNode(10);
    cout << s.isValidBST(root) << endl;
    return 0;
}
