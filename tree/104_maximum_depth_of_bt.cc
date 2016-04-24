//
// Created by Neptune on 4/24/16.
//

/*
 * Given a binary tree, find its maximum depth.
 * The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 */

#include <vector>
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
    int maxDepth(TreeNode *root) {
        if (!root)
            return 0;

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

int main() {
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(1);
    root->left->left->left = new TreeNode(1);
    root->left->left->left->right = new TreeNode(1);
    cout << Solution().maxDepth(root) << endl;
    return 0;
}
