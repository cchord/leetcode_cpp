//
// Created by Neptune on 4/24/16.
//
/*
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values
 * along the path equals the given sum.
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
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root)
            return false;

        if (!root->left && !root->right)
            return sum == root->val;

        return hasPathSum(root->left, sum - root->val) ||
               hasPathSum(root->right, sum - root->val);
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(3);
    cout << Solution().hasPathSum(root, 5) << endl;
    cout << Solution().hasPathSum(root, 6) << endl;
    cout << Solution().hasPathSum(root, 7) << endl;
    return 0;
}
