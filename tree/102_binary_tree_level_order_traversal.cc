//
// Created by Neptune on 4/23/16.
//
/*
 * Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 * For example:
 *      Given binary tree {3,9,20,#,#,15,7},
 */

#include <vector>
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
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;

        if (!root)
            return res;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            unsigned long size = q.size();
            vector<int> v;

            for (unsigned long i = 0; i < size; ++i) {
                auto node = q.front();
                q.pop();
                v.push_back(node->val);

                if (node->left) q.push(node->left);

                if (node->right) q.push(node->right);
            }

            res.push_back(v);
        }

        return res;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->left->right = new TreeNode(6);
    auto res = Solution().levelOrder(root);

    for (auto &vec : res) {
        for (auto n : vec)
            cout << n << " ";

        cout << endl;
    }

    return 0;
}
