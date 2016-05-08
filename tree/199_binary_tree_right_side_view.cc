//
// Created by Neptune on 5/8/16.
//

/*
 * Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes
 * you can see ordered from top to bottom.
 *
 * For example:
 *      Given the following binary tree,
 *          1            <---
 *        /   \
 *       2     3         <---
 *        \     \
 *         5     4       <---
 *      You should return [1, 3, 4].
 */

#include <vector>
#include <queue>
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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;

        if (!root)
            return res;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            auto sz = q.size();
            res.push_back(q.back()->val);

            for (int i = 0; i < sz; ++i) {
                auto node = q.front();
                q.pop();

                if (node->left) q.push(node->left);

                if (node->right) q.push(node->right);
            }
        }

        return res;
    }
};

int main() {
    TreeNode *t = new TreeNode(1);
    t->left = new TreeNode(2);
    t->left->left = new TreeNode(3);
    t->right = new TreeNode(5);
    t->left->right = new TreeNode(4);
    auto res = Solution().rightSideView(t);

    for (auto n : res)
        cout << n << " ";
}

