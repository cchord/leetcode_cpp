//
// Created by Neptune on 5/8/16.
//

/*
 * Given a binary tree, return all root-to-leaf paths.
 *
 * For example, given the following binary tree:
 *
 *      1
 *    /   \
 *   2     3
 *    \
 *     5
 * All root-to-leaf paths are:
 *
 * ["1->2->5", "1->3"]
 */

#include <string>
#include <vector>
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
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> res;
        dfs(root, res, "");
        return res;
    }

    void dfs(TreeNode *root, vector<string> &res, string path) {
        if (!root) return;

        auto valStr = to_string(root->val);
        path += path.empty() ? valStr : "->" + valStr;

        if (!root->left && !root->right) {
            res.emplace_back(path);
            return;
        }

        if (root->left)  dfs(root->left, res, path);

        if (root->right) dfs(root->right, res, path);
    }
};

int main() {
    TreeNode *t = new TreeNode(1);
    t->left = new TreeNode(2);
    t->right = new TreeNode(3);
    t->left->right = new TreeNode(5);
    auto res = Solution().binaryTreePaths(t);

    for (auto &s : res)
        cout << s << endl;

    return 0;
}
