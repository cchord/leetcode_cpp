//
// Created by Neptune on 5/9/16.
//

/*
 * Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
 *
 * Note:
 *
 *      You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
 *
 * Follow up:
 *      What if the BST is modified (insert/delete operations) often and you need to find the kth smallest
 *      frequently? How would you optimize the kthSmallest routine?
 *
 * Hint:
 *
 *      Try to utilize the property of a BST.
 *      What if you could modify the BST node's structure?
 *      The optimal runtime complexity is O(height of BST).
 */

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
    int kthSmallest(TreeNode *root, int k) {
        if (!root)
            return 0;

        int count = 0, result;
        dfs(root, count, result, k);
        return result;
    }

    // in-order travesal
    void dfs(TreeNode *tree, int &count, int &result, int k) {
        if (!tree) return;

        dfs(tree->left, count, result, k);

        if (++count == k) {
            result = tree->val;
            return;
        }

        dfs(tree->right, count, result, k);
    }
};

int main() {
    TreeNode *t = new TreeNode(4);
    t->left = new TreeNode(2);
    t->left->left = new TreeNode(1);
    t->right = new TreeNode(5);
    t->left->right = new TreeNode(3);
    auto res = Solution().kthSmallest(t, 5);
    cout << res << endl;
    return 0;
}
