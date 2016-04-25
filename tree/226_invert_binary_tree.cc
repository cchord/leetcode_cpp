//
// Created by Neptune on 4/25/16.
//

/*
 * Invert a binary tree.
 */

#include <queue>
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
    TreeNode *invertTree(TreeNode *root) {
        if (!root) return nullptr;

        auto left = invertTree(root->left);
        auto right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
};

void levelOrder(TreeNode *tree) {
    if (!tree)
        return;

    queue<TreeNode *> q;
    q.push(tree);

    while (!q.empty()) {
        int sz = q.size();

        for (int i = 0; i < sz; ++i) {
            auto node = q.front();
            q.pop();
            cout << node->val << " ";

            if (node->left) q.push(node->left);

            if (node->right) q.push(node->right);
        }

        cout << endl;
    }
}

int main() {
    TreeNode *t = new TreeNode(1);
    t->left = new TreeNode(2);
    t->right = new TreeNode(3);
    t->left->left = new TreeNode(4);
    t->left->right = new TreeNode(5);
    t->right->left = new TreeNode(6);
    t->right->right = new TreeNode(7);
    levelOrder(t);
    levelOrder(Solution().invertTree(t));
    return 0;
}
