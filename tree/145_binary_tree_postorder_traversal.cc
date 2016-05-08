//
// Created by Neptune on 5/8/16.
//

/*
 * Given a binary tree, return the postorder traversal of its nodes' values.
 *
 * For example:
 * Given binary tree {1,#,2,3},
 *  1
 *   \
 *    2
 *   /
 *  3
 *  return [3,2,1].
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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;

        if (!root)
            return res;

        stack<pair<TreeNode *, int>> s;

        while (root || !s.empty()) {
            while (root) {
                s.push(make_pair(root, 0));
                root = root->left;
            }

            auto p = s.top();
            s.pop();

            if (p.second == 1)
                res.push_back(p.first->val);
            else {
                s.push(make_pair(p.first, 1));
                root = p.first->right;
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
    auto res = Solution().postorderTraversal(t);

    for (auto n : res)
        cout << n << " ";

    return 0;
}
