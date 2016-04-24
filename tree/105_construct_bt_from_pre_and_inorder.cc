//
// Created by Neptune on 4/24/16.
//
/*
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * Note:
 *      You may assume that duplicates do not exist in the tree.
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }

    TreeNode *buildTree(vector<int> &pre, int sp, int ep, vector<int> &in, int si, int ei) {
        if (sp == ep || si == ei)
            return nullptr;

        auto rootVal = pre[sp];
        int distance = std::distance(in.begin() + si, find(in.begin() + si, in.begin() + ei, rootVal));
        TreeNode *root = new TreeNode(rootVal);
        root->left  = buildTree(pre, sp + 1, sp + distance + 1, in, si, si + distance);
        root->right = buildTree(pre, sp + 1 + distance, ep, in, si + distance + 1, ei);
        return root;
    }

    static void prt(TreeNode *root) {
        if (root) {
            cout << root->val << " ";
            prt(root->left);
            prt(root->right);
        }
    }
};

int main() {
    vector<int> pre{5, 2, 1, 3};
    vector<int> in{1, 2, 5, 3};
    auto root = Solution().buildTree(pre, in);
    Solution::prt(root);
    return 0;
}
