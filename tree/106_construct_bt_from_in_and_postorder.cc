//
// Created by Neptune on 4/24/16.
//

/*
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 * Note:
 *      You may assume that duplicates do not exist in the tree.
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTree(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }

    // follow STL convention, ei and ep is are like iter::end()...
    TreeNode *buildTree(vector<int> &in, int si, int ei, vector<int> &post, int sp, int ep) {
        if (si == ei || sp == ep)
            return nullptr;

        auto rootVal = post[ep - 1];
        auto dist = distance(in.begin() + si, find(in.begin() + si, in.begin() + ei, rootVal));
        auto root = new TreeNode(rootVal);
        root->left  = buildTree(in, si, si + dist, post, sp, sp + dist);
        root->right = buildTree(in, si + dist + 1, ei, post, sp + dist, ep - 1);
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
    vector<int> in{1, 2, 5, 3};
    vector<int> post{1, 2, 3, 5};
    auto root = Solution().buildTree(in, post);
    Solution::prt(root);
    return 0;
}
