//
// Created by Neptune on 4/23/16.
//

/*
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * Note: Recursive solution is trivial, could you do it iteratively?
 */

#include <vector>
#include <stack>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> s;

        while (root || !s.empty()) {
            while (root) {
                s.push(root);
                root = root->left;
            }

            auto node = s.top();
            s.pop();
            res.push_back(node->val);
            root = node->right;
        }

        return res;
    }
};

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    auto res = Solution().inorderTraversal(root);

    for (auto n : res)
        cout << n << " ";

    cout << endl;
    return 0;
}
