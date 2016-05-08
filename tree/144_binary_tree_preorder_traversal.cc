//
// Created by Neptune on 5/8/16.
//

/*
 * Given a binary tree, return the preorder traversal of its nodes' values.
 *
 * For example:
 * Given binary tree {1,#,2,3},
 *
 *      1
 *       \
 *         2
 *       /
 *      3
 *
 *      return [1,2,3].
 *
 * Note: Recursive solution is trivial, could you do it iteratively?
 */

#include <vector>
#include <stack>
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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;

        if (!root)
            return res;

        stack<TreeNode *> s;

        while (root || !s.empty()) {
            while (root) {
                res.emplace_back(root->val);
                s.push(root);
                root = root->left;
            }

            root = s.top()->right;
            s.pop();
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
    auto res = Solution().preorderTraversal(t);

    for (auto n : res)
        cout << n << " ";

    return 0;
}
