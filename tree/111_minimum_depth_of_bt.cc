//
// Created by Neptune on 4/24/16.
//

/*
 * Given a binary tree, find its minimum depth.
 * The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
    #if 0
    int minDepth(TreeNode *root) {
        if (!root)
            return 0;

        int minimum = numeric_limits<int>::max();
        minDepth(root, minimum, 0);
        return minimum;
    }

    void minDepth(TreeNode *root, int &minimum, int count) {
        if (!root->left && !root->right) {
            minimum = min(minimum, count + 1);
            return;
        }

        if (root->left)
            minDepth(root->left, minimum, count + 1);

        if (root->right)
            minDepth(root->right, minimum, count + 1);
    }
    #endif
    int minDepth(TreeNode *root) {
        if (!root)
            return 0;

        if (root->left && root->right)
            return min(minDepth(root->left), minDepth(root->right)) + 1;
        else
            return max(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

int main() {
    TreeNode *tree = new TreeNode(10);
    tree->left = new TreeNode(0);
    tree->right = new TreeNode(0);
    tree->left->left = new TreeNode(0);
    tree->left->left->left = new TreeNode(0);
    cout << Solution().minDepth(tree) << endl;
    return 0;
}
