//
// Created by Neptune on 4/23/16.
//

/*
 * Given two binary trees, write a function to check if they are equal or not.
 * Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p && !q)
            return true;

        if ((!p || !q) || p->val != q->val)
            return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main() {
    TreeNode *t1 = new TreeNode(1);
    t1->left = new TreeNode(2);
    TreeNode *t2 = new TreeNode(1);
    t2->left = new TreeNode(4);
    cout << Solution().isSameTree(t1, t2)  << endl;
    cout << Solution().isSameTree(nullptr, nullptr)  << endl;
    cout << Solution().isSameTree(t1, nullptr)  << endl;
    return 0;
}
