//
// Created by Neptune on 4/24/16.
//
/*
 * Given a binary tree, flatten it to a linked list in-place.
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
    void flatten(TreeNode *root) {
        if (!root)
            return;

        flatten(root->left);
        flatten(root->right);
        auto l = root->left, r = root->right;

        if (l) {
            root->right = l;
            auto tail = l;

            while (tail->right)
                tail = tail->right;

            tail->right = r;
            root->left = nullptr;
        } else
            root->right = r;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(3);
    Solution().flatten(root);
    cout << endl;
    return 0;
}
